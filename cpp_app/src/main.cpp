#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main()
{
    cout << "=== Vision App Dia 1 Iniciado ===" << endl;

    // Cargar imagen de prueba
    Mat img = imread("ejemplo.png");

    if (img.empty()) {
        cerr << "Error: No se pudo cargar la imagen test.png" << endl;
        return -1;
    }

    // Mostrar la imagen original
    imshow("Original", img);

    // Convertir a gris
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // Mostrar la imagen procesada
    imshow("Gris", gray);

    cout << "Presiona una tecla para salir..." << endl;
    waitKey(0);

    return 0;
}
*/
void run_day2();

int main()
{
    std::cout << "=== Vision App Dia 2 Iniciado ===" << std::endl;

    run_day2();

    return 0;
}
