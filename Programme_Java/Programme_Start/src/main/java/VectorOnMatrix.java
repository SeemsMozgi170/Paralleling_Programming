import java.util.ArrayList;

public class VectorOnMatrix {
    int size, countThread, splitMatrix;
    int[][] matrixB;
    int[] vectorA,resultVector;

    VectorOnMatrix(int[] vectorA, int[][] matrixB, int countThread){
        this.vectorA = vectorA;
        this.matrixB = matrixB;
        this.countThread = countThread;
        this.size = vectorA.length;
        splitMatrix = (int) Math.ceil(matrixB[0].length/(double)countThread);
        resultVector = new int[matrixB[0].length];
        for (int i = 0; i < countThread; i++){
            new MultiPlyingVectorOnMatrixWithMultiThreading(i).run();
        }
    }

    public void multiplyingPartsVectorOnMatrix(int from){
        int to = Math.min(matrixB[0].length,(from + 1)*splitMatrix);
        for (int j = from*splitMatrix; j < to; j++){
            for (int i = 0; i < matrixB.length; i++){
                resultVector[j] += vectorA[i] * matrixB[i][j];
            }
        }
    }

    private class MultiPlyingVectorOnMatrixWithMultiThreading implements Runnable {
        int from;

        MultiPlyingVectorOnMatrixWithMultiThreading(int from){
            this.from = from;
        }

        public void run() {
            multiplyingPartsVectorOnMatrix(from);
        }
    }
}