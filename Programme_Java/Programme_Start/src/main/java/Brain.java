import java.util.ArrayList;

public class Brain {
    public static void main(String[] args) {
        double startTime;
        GenerateObjects generateObjects = new GenerateObjects();

        System.out.println("//-------------------------------------Вектор на Число--------------------------------------------------");
        int[] vector0 = generateObjects.generateVector(50000);
        int number0 = generateObjects.generateNumber();

        startTime = System.currentTimeMillis();
        new VectorOnNumber(vector0,number0,1);
        System.out.println("Time(Vector on Number(1)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnNumber(vector0,number0,2);
        System.out.println("Time(Vector on Number(2)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnNumber(vector0,number0,4);
        System.out.println("Time(Vector on Number(4)) = " + (System.currentTimeMillis() - startTime) + " msec");

        System.out.println("//-------------------------------------Вектор на Вектор--------------------------------------------------");
        int[] vectorA1 = generateObjects.generateVector(50000);
        int[] vectorB1 = generateObjects.generateVector(50000);

        startTime = System.currentTimeMillis();
        new VectorOnVector(vectorA1,vectorB1,1);
        System.out.println("Time(Vector on Vector(1)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnVector(vectorA1,vectorB1,2);
        System.out.println("Time(Vector on Vector(2)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnVector(vectorA1,vectorB1,4);
        System.out.println("Time(Vector on Vector(4)) = " + (System.currentTimeMillis() - startTime) + " msec");

        System.out.println("//-------------------------------------Матрица на Число--------------------------------------------------");
        int[][] matrix2 = generateObjects.generateMatrix(10000,15000);
        int number2 = generateObjects.generateNumber();

        startTime = System.currentTimeMillis();
        new MatrixOnNumber(matrix2,number2,1);
        System.out.println("Time(Matrix on Number(1)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new MatrixOnNumber(matrix2,number2,2);
        System.out.println("Time(Matrix on Number(2)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new MatrixOnNumber(matrix2,number2,4);
        System.out.println("Time(Matrix on Number(4)) = " + (System.currentTimeMillis() - startTime) + " msec");

        System.out.println("//-------------------------------------Вектор на Матрицу--------------------------------------------------");
        int[] vectorA2 = generateObjects.generateVector(1000);
        int[][] matrixB2 = generateObjects.generateMatrix(1000,1000);

        startTime = System.currentTimeMillis();
        new VectorOnMatrix(vectorA2,matrixB2,1);
        System.out.println("Time(Matrix on Vector(1)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnMatrix(vectorA2,matrixB2,2);
        System.out.println("Time(Matrix on Vector(2)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new VectorOnMatrix(vectorA2,matrixB2,4);
        System.out.println("Time(Matrix on Vector(4)) = " + (System.currentTimeMillis() - startTime) + " msec");

        System.out.println("//-------------------------------------Матрица на Матрицу--------------------------------------------------");
        int[][] matrixA3 = generateObjects.generateMatrix(1000,1000);
        int[][] matrixB3 = generateObjects.generateMatrix(1000,1000);

        startTime = System.currentTimeMillis();
        new MatrixOnMatrix(matrixA3,matrixB3,1);
        System.out.println("Time(Matrix on Matrix(1)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new MatrixOnMatrix(matrixA3,matrixB3,2);
        System.out.println("Time(Matrix on Matrix(2)) = " + (System.currentTimeMillis() - startTime) + " msec");

        startTime = System.currentTimeMillis();
        new MatrixOnMatrix(matrixA3,matrixB3,4);
        System.out.println("Time(Matrix on Matrix(4)) = " + (System.currentTimeMillis() - startTime) + " msec");
    }
}
