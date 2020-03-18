import java.util.ArrayList;

public class MatrixOnNumber {
    int number, countThread, splitMatrix;
    int [][] matrix, resultMatrix;

    MatrixOnNumber(int[][] matrix, int number, int countThread){
        this.matrix = matrix;
        this.countThread = countThread;
        this.number = number;
        splitMatrix = (int) Math.ceil(matrix.length/(double)countThread);
        resultMatrix = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < countThread; i++){
            new MultiPlyingMatrixOnNumberWithMultiThreading(i).run();
        }
    }

    public void multiplyingPartsMatrixOnNumber(int from) {
        int to = Math.min(matrix.length, (from + 1) * splitMatrix);
        for (int i = from * splitMatrix; i < to; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                resultMatrix[i][j] = matrix[i][j] * number;
            }
        }
    }

    private class MultiPlyingMatrixOnNumberWithMultiThreading implements Runnable{
        int from;

        MultiPlyingMatrixOnNumberWithMultiThreading(int from){
            this.from = from;
        }

        public void run() {
            multiplyingPartsMatrixOnNumber(from);
        }
    }

}
