import java.util.ArrayList;
import java.util.Random;

public class Operations {
    Random random = new Random();
    public int n,m;
    long startTime;

    public void vectorOnNumber(){
        startTime = System.currentTimeMillis();
        ArrayList<Integer> vector1 = new ArrayList<Integer>();
        int number1 = random.nextInt(2000) - 1000;
        n = 1000;
        for (int i= 0; i < n; i++){
            vector1.add((random.nextInt(2000) - 1000)*number1);
        }
        System.out.println("Time(Vector on Number) = " + (System.currentTimeMillis() - startTime) + " msec");
    }

    public void vectorOnVector(){
        startTime = System.currentTimeMillis();
        ArrayList<Integer> vector1 = new ArrayList<Integer>();
        ArrayList<Integer> vector2 = new ArrayList<Integer>();
        n = 1000;
        int res = 0;
        for (int i= 0; i < n; i++){
            vector1.add(random.nextInt(2000) - 1000);
            vector2.add(random.nextInt(2000) - 1000);
            res += vector1.get(i) * vector2.get(i);
        }
        System.out.println("Time(Vector on Vector) = " + (System.currentTimeMillis() - startTime) + " msec");
    }

    public void matrixOnNumber(){
        startTime = System.currentTimeMillis();
        ArrayList<ArrayList<Integer>> matrix1 = new ArrayList<ArrayList<Integer>>();
        int number1 = random.nextInt(2000) - 1000;
        n = 200;
        m = 300;
        for (int i = 0; i < n; i++) {
            matrix1.add(new ArrayList<Integer>(m));
            for (int j = 0; j < m; j++)
                matrix1.get(i).add((random.nextInt(2000) - 1000)*number1);
        }
        System.out.println("Time(Matrix on Number) = " + (System.currentTimeMillis() - startTime) + " msec");
    }

    public void matrixOnVector(){
        startTime = System.currentTimeMillis();
        ArrayList<ArrayList<Integer>> matrix1 = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> vector1 = new ArrayList<Integer>();
        ArrayList<Integer> resVector = new ArrayList<Integer>();
        n = 200;
        m = 300;
        for (int i = 0; i < n; i++) {
            matrix1.add(new ArrayList<Integer>(m));
            for (int j = 0; j < m; j++)
                matrix1.get(i).add(random.nextInt(2000) - 1000);
        }
        for (int i= 0; i < m; i++){
            vector1.add(random.nextInt(2000) - 1000);
        }
        for (int i = 0; i < n; i++) {
            resVector.add(0);
            for (int j = 0; j < m; j++){
                resVector.set(resVector.size()-1,resVector.get(resVector.size()-1) + matrix1.get(i).get(j)*vector1.get(j));
            }
        }
        System.out.println("Time(Matrix on Vector) = " + (System.currentTimeMillis() - startTime) + " msec");
    }

    public void matrixOnMatrix(){
        startTime = System.currentTimeMillis();
        ArrayList<ArrayList<Integer>> matrix1 = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> matrix2 = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> resMatrix = new ArrayList<ArrayList<Integer>>();
        n = 1000;
        m = 1000;
        for (int i = 0; i < n; i++) {
            matrix1.add(new ArrayList<Integer>(m));
            for (int j = 0; j < m; j++)
                matrix1.get(i).add(random.nextInt(2000) - 1000);
        }
        for (int i = 0; i < m; i++) {
            matrix2.add(new ArrayList<Integer>(n));
            for (int j = 0; j < n; j++)
                matrix2.get(i).add(random.nextInt(2000) - 1000);
        }
        for (int i = 0; i < matrix1.size(); i++){
            resMatrix.add(new ArrayList<Integer>(matrix2.get(i).size()));
            for (int j = 0; j < matrix2.get(i).size(); j++){
                int sum = 0;
                for (int k = 0; k < matrix2.size(); k++)
                    sum += matrix1.get(i).get(k) * matrix2.get(k).get(j);
                resMatrix.get(i).add(sum);
            }
        }
        System.out.println("Time(Matrix on Matrix) = " + (System.currentTimeMillis() - startTime) + " msec");
    }
}
