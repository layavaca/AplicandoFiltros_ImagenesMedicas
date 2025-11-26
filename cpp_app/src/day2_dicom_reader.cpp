#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageRegionIterator.h>

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

template <typename TImage>
cv::Mat itkToMat(typename TImage::Pointer image){
    using ImageType = TImage;

    auto region = image->GetLargestPossibleRegion();
    auto size   = region.GetSize();

    cv::Mat mat(size[1], size[0], CV_32FC1);

    itk::ImageRegionConstIterator<ImageType> it(image, region);

    int y = 0, x = 0;

    for (it.GoToBegin(); !it.IsAtEnd(); ++it)
    {
        mat.at<float>(y, x) = static_cast<float>(it.Get());

        if (++x >= size[0]) { x = 0; y++; }
    }

    return mat;
}

void run_day2()
{
    using PixelType = short;
    static const unsigned int Dimension = 2;
    using ImageType = itk::Image<PixelType, Dimension>;
    using ReaderType = itk::ImageFileReader<ImageType>;

    std::string path = "../input/test1.IMA";

    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(path);

    try {
        reader->Update();
    }
    catch (itk::ExceptionObject& e) {
        std::cerr << "Error al leer IMA: " << e << std::endl;
        return;
    }

    ImageType::Pointer image = reader->GetOutput();

    // 🔥 CORRECCIÓN IMPORTANTE: especificar la plantilla
    cv::Mat slice = itkToMat<ImageType>(image);

    // Guardar PNG
    cv::imwrite("../output/output_slice.png", slice);

    // Mostrar
    cv::imshow("Slice IMA", slice);
    cv::waitKey(0);

    std::cout << "Día 2 completado con éxito." << std::endl;
}
