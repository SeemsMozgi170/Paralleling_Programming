import java.util.ArrayList;

public class VectorOnVector {
    int size, countThread = 1, splitVector, result;
    int[] vectorA;
    int[] vectorB;

    public VectorOnVector(int[] vectorA, int[] vectorB, int countThread){
        this.vectorA = vectorA;
        this.vectorB = vectorB;
        this.size = vectorA.length;
        this.countThread = countThread;
        splitVector = (int) Math.ceil(this.size/(double)countThread);
        for (int i = 0; i < countThread; i++){
            new MultiPlyingVectorsWithMultiThreading(i).run();
        }
    }

    public void multiplyingPartsOfVectors(int from){
        int to = Math.min(vectorA.length,(from + 1)*splitVector);
        for (int i = from*splitVector; i < to; i++) result += vectorA[i] * vectorB[i];
    }

    private class MultiPlyingVectorsWithMultiThreading implements Runnable{
        int from;

        MultiPlyingVectorsWithMultiThreading(int from){
            this.from = from;
        }

        public void run() {
            multiplyingPartsOfVectors(from);
        }
    }
}
