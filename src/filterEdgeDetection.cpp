#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#define WINDOWS_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#pragma warning(disable : 4819)
#endif

#include "utilnpp/Exceptions.h"
#include "utilnpp/ImageIO.h"
#include "utilnpp/ImagesCPU.h"
#include "utilnpp/ImagesNPP.h"

#include <string.h>
#include <fstream>
#include <iostream>
#include <format>
#include <sstream>

// #include <cuda_runtime.h>
// #include <npp.h>

// #include "helper_cuda.h"
#include "common/helper_string.h"

// bool printfNPPinfo(int argc, char *argv[])
// {
//   const NppLibraryVersion *libVer = nppGetLibVersion();

//   printf("NPP Library Version %d.%d.%d\n", libVer->major, libVer->minor,
//          libVer->build);

//   int driverVersion, runtimeVersion;
//   cudaDriverGetVersion(&driverVersion);
//   cudaRuntimeGetVersion(&runtimeVersion);

//   printf("  CUDA Driver  Version: %d.%d\n", driverVersion / 1000,
//          (driverVersion % 100) / 10);
//   printf("  CUDA Runtime Version: %d.%d\n", runtimeVersion / 1000,
//          (runtimeVersion % 100) / 10);

//   // Min spec is SM 1.0 devices
//   bool bVal = checkCudaCapabilities(1, 0);
//   return bVal;
// }

// void processImageBatch(const std::vector<std::vector<std::string>>& sequence)
// {
//     for(auto &sFilename:sequence)
//     {
        // try
//          {
//         // declare a host image object for an 8-bit grayscale image
//         npp::ImageCPU_8u_C1 oHostSrc;
//         // load gray-scale image from disk
//         npp::loadImage(sFilename, oHostSrc);
//         // declare a device image and copy construct from the host image,
//         // i.e. upload host to device
//         npp::ImageNPP_8u_C1 oDeviceSrc(oHostSrc);

//         // create struct with box-filter mask size
//         NppiSize oMaskSize = {5, 5};

//         NppiSize oSrcSize = {(int)oDeviceSrc.width(), (int)oDeviceSrc.height()};
//         NppiPoint oSrcOffset = {0, 0};

//         // create struct with ROI size
//         NppiSize oSizeROI = {(int)oDeviceSrc.width(), (int)oDeviceSrc.height()};
//         // allocate device image of appropriately reduced size
//         npp::ImageNPP_8u_C1 oDeviceDst(oSizeROI.width, oSizeROI.height);
//         // set anchor point inside the mask to (oMaskSize.width / 2,
//         // oMaskSize.height / 2) It should round down when odd
//         NppiPoint oAnchor = {oMaskSize.width / 2, oMaskSize.height / 2};

//         // run box filter
//         NPP_CHECK_NPP(nppiFilterBoxBorder_8u_C1R(
//             oDeviceSrc.data(), oDeviceSrc.pitch(), oSrcSize, oSrcOffset,
//             oDeviceDst.data(), oDeviceDst.pitch(), oSizeROI, oMaskSize, oAnchor,
//             NPP_BORDER_REPLICATE));

//         // declare a host image for the result
//         npp::ImageCPU_8u_C1 oHostDst(oDeviceDst.size());
//         // and copy the device result data into it
//         oDeviceDst.copyTo(oHostDst.data(), oHostDst.pitch());

//         saveImage(sResultFilename, oHostDst);
//         std::cout << "Saved image: " << sResultFilename << std::endl;

//         nppiFree(oDeviceSrc.data());
//         nppiFree(oDeviceDst.data());

//         exit(EXIT_SUCCESS);
//     }
// }
// catch (npp::Exception &rException)
// {
// std::cerr << "Program error! The following exception occurred: \n";
// std::cerr << rException << std::endl;
// std::cerr << "Aborting." << std::endl;

// exit(EXIT_FAILURE);
// }
// catch (...)
// {
// std::cerr << "Program error! An unknow type of exception occurred. \n";
// std::cerr << "Aborting." << std::endl;

// exit(EXIT_FAILURE);
// return -1;
// }

int main(int argc, char *argv[])
{
  printf("%s Starting...\n\n", argv[0]);

    std::string sFilename;
    char *filePath;

    try
    {
       findCudaDevice(argc, (const char **)argv);

        if (printfNPPinfo(argc, argv) == false)
        {
        exit(EXIT_SUCCESS);
        }
    }
    catch (npp::Exception &rException)
    {
        std::cerr << "Program error! The following exception occurred: \n";
        std::cerr << rException << std::endl;
        std::cerr << "Aborting." << std::endl;

        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << "Program error! An unknow type of exception occurred. \n";
        std::cerr << "Aborting." << std::endl;

        exit(EXIT_FAILURE);
        return -1;
    }

    std::vector<std::vector<std::string> > sequences(0,std::vector<std::string>());
    std::string basePath = "data/sequences/";

    std::cout << "basePath: " << basePath << std::endl;

    for(const std::string& sequence: {"6.1", "6.2", "6.3", "motion"})
    {   
        std::vector<std::string> file_sequence;
        for(int i=1;i<=32;i++)
        {
            // std::string filename = basePath + sequence + ((sequence == "motion") ? std::format("{:02d}", i) + ".512.tiff" : std::format(".{:02d}.tiff", i));
            std::ostringstream filenameStream;
            filenameStream << basePath << sequence;
            if(sequence == "motion")
            {
                filenameStream << std::setw(2) << std::setfill('0') << i << ".512.tiff";
            }
            else
            {
                filenameStream << "." << std::setw(2) << std::setfill('0') << i << ".tiff";
            }
            std::string filename = filenameStream.str();

            std::ifstream infile(filename, std::ifstream::in);
            if (infile.good())
            {
                // std::cout<< "filename: " << filename << std::endl;
                file_sequence.push_back(filename);
            }
            else
            {
                // std::cout << "file not found: " << filename << std::endl;
                break;
            }
        }            

        sequences.push_back(file_sequence);
    }

    // processImageBatch(sequence);

//     int file_errors = 0;
//     std::ifstream infile(sFilename.data(), std::ifstream::in);

//     if (infile.good())
//     {
//       std::cout << "boxFilterNPP opened: <" << sFilename.data()
//                 << "> successfully!" << std::endl;
//       file_errors = 0;
//       infile.close();
//     }
//     else
//     {
//       std::cout << "boxFilterNPP unable to open: <" << sFilename.data() << ">"
//                 << std::endl;
//       file_errors++;
//       infile.close();
//     }

//     if (file_errors > 0)
//     {
//       exit(EXIT_FAILURE);
//     }

//     std::string sResultFilename = sFilename;

//     std::string::size_type dot = sResultFilename.rfind('.');

//     if (dot != std::string::npos)
//     {
//       sResultFilename = sResultFilename.substr(0, dot);
//     }

//     sResultFilename += "_boxFilter.pgm";

//     if (checkCmdLineFlag(argc, (const char **)argv, "output"))
//     {
//       char *outputFilePath;
//       getCmdLineArgumentString(argc, (const char **)argv, "output",
//                                &outputFilePath);
//       sResultFilename = outputFilePath;
//     }


  return 0;
}
