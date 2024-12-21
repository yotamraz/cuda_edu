/*
Kernels

CUDA C++ extends C++ by allowing the programmer to define C++ functions, called kernels, that, when called, are executed N times in parallel by N different CUDA threads, as opposed to only once like regular C++ functions.

A kernel is defined using the __global__ declaration specifier and the number of CUDA threads that execute that kernel for a given kernel call is specified using a new <<<...>>>execution configuration syntax (see C++ Language Extensions). Each thread that executes the kernel is given a unique thread ID that is accessible within the kernel through built-in variables.

As an illustration, the following sample code, using the built-in variable threadIdx, adds two vectors A and B of size N and stores the result into vector C

*/

#include <vector>
#include <random>
#include <ctime>

__global__ void AddVec(std::vector<float>* A, std::vector<float>* B, std::vector<float>* C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    NumOfThreads = 16
    std::vector<float> A(NumOfThreads);
    std::vector<float> B(NumOfThreads);
    std::vector<float> C(NumOfThreads);

    std::default_random_engine generator(static_cast<unsigned int>(std::time(0)));
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    for (int i = 0; i < NumOfThreads; ++i) {
        A[i] = distribution(generator);
        B[i] = distribution(generator);
    }

    // Launch the kernel
    AddVec<<<0, NumOfThreads>>>(A, B, C);

    std::cout << "Vector C: ";
    for (const auto& val : C) std::cout << val << " ";
}