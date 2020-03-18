import java.util.ArrayList;

public class GenerateObjects {
    public int[][] generateMatrix(int rows, int colums){
        int[][] M = new int[rows][colums];
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < colums; j++){
                M[i][j] = 2;
            }
        }
        return M;
    }

    public int generateNumber(){
        return 1638;
    }

    public int[] generateVector(int size){
        int[] V = new int[size];
        for (int i = 0; i < size; i++) V[i] = 2;
        return V;
    }
}
