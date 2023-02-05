#ifndef BOX_KERNEL_H_
#define BOX_KERNEL_H_
#include <vector>
#include <stdexcept>
#include <numeric>
namespace EdgeDetections {
class BoxKernel {
public:

    BoxKernel(const std::initializer_list<std::initializer_list<double>> &t_kernel) {
        CheckKernel(t_kernel);
        std::copy(t_kernel.begin(), t_kernel.end(), std::back_inserter(kernel));
    }

    ~BoxKernel() {}

    // Delete copy constructor
    BoxKernel(const BoxKernel &) = delete;
    void operator = (const BoxKernel &) = delete;

    // Delete move constructor
    BoxKernel (BoxKernel &&) = delete;
    void operator  = (BoxKernel &&)  = delete;
    
    BoxKernel &operator = (const std::initializer_list<std::initializer_list<double>> &t_kernel) {
        CheckKernel(t_kernel);
        std::copy(t_kernel.begin(), t_kernel.end(), std::back_inserter(kernel));
        return *this;
    }

    const std::vector<std::vector<double>> &GetKernel()const {
        return kernel;
    }
    
    double GetValueAt(const int row, const int column) {
        if(row < 0 || column < 0  || column >= kernel.size() || row >= kernel.size())
            throw std::runtime_error("Out of bounds !");
        return kernel[row][column];
    }
    
    std::vector<double> &operator [](int index){
        if(index < 0 ||  index >= kernel.size())
            throw std::runtime_error("Out of bounds !");
        return kernel[index];
    }
    
    double GetTotal()const {
        return std::accumulate(kernel.begin(), kernel.end(), 0.0f, [](auto total, const auto &right) {
            return std::accumulate(right.begin(), right.end(), total);
        });
    }


private:
    void CheckKernel(const std::initializer_list<std::initializer_list<double>> &t_kernel) {
        int size = t_kernel.size();
        if(size == 0)
            std::runtime_error("Kernel must have element !");
        for(auto &row:t_kernel) {
            if(row.size() != size)
                throw std::runtime_error("Row and column sizes are not equal !");
        }
    }
    std::size_t size;
    std::vector<std::vector<double>> kernel;
};
}
#endif
