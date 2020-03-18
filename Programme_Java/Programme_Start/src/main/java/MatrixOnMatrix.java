import java.util.ArrayList;

public class MatrixOnMatrix {
    int[][] matrixA, matrixB, resultMatrix;
    int countThread,splitMatrix;

    public MatrixOnMatrix(int[][] matrixA, int[][] matrixB, int countThread){
        this.matrixA = matrixA;
        this.matrixB = matrixB;
        this.countThread = countThread;
        splitMatrix = (int) Math.ceil(matrixA.length/(double)countThread);
        resultMatrix = new int[matrixA.length][matrixB[0].length];
        for (int i = 0; i < countThread; i++){
            new MultiPlyingMatrixOnMatrixWithMultiThreading(i).run();
        }
    }

    public void multiplyingPartsMatrixOnMatrix(int from){
        int to = Math.min(matrixA.length,(from + 1)*splitMatrix);
        for (int i = from*splitMatrix; i < to; i++){
            for (int c = 0; c < matrixB[0].length; c++){
                for (int r = 0; r < matrixB.length; r++){
                    resultMatrix[i][c] += matrixA[i][r] * matrixB[r][c];
                }
            }
        }
    }

    public class MultiPlyingMatrixOnMatrixWithMultiThreading implements Runnable{
        int from;

        MultiPlyingMatrixOnMatrixWithMultiThreading(int from){
            this.from = from;
        }

        public void run() {
            multiplyingPartsMatrixOnMatrix(from);
        }
    }
}
