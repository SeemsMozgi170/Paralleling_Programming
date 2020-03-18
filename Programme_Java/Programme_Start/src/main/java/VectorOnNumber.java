import java.util.ArrayList;

public class VectorOnNumber {
    int number, splitVector, countThread;
    int[] vector, resultVector;

    VectorOnNumber(int[] vector,int number, int countThread){
        this.countThread = countThread;
        this.vector = vector;
        this.number = number;
        splitVector = (int) Math.ceil(vector.length/(double)countThread);
        resultVector = new int[vector.length];
        for (int i = 0; i < countThread; i++){
            new MultiPlyingVectorOnNumberWithMultiThreading(i).run();
        }
    }

    public void multiplyingPartsVectorOnNumber(int from) {
        int to = Math.min(vector.length, (from + 1) * splitVector);
        for (int i = from * splitVector; i < to; i++) {
            resultVector[i] = vector[i] * number;
        }
    }

    private class MultiPlyingVectorOnNumberWithMultiThreading implements Runnable{
        int from;

         MultiPlyingVectorOnNumberWithMultiThreading(int from){
             this.from = from;
         }

        public void run() {
            multiplyingPartsVectorOnNumber(from);
        }
    }
}
