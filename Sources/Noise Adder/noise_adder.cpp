//
// Created by Szymon Mrozek on 17.08.2017.
//

#include "noise_adder.h"

NoiseAdder::NoiseAdder(double mean, double var) : mean_(mean), var_(var), engine_(new std::default_random_engine()),
                                                    distribution_(new std::normal_distribution<double>(mean_, var_)) {

}

void NoiseAdder::addNoiseToStream(std::vector<std::complex<double>> *input_stream) {

    output_stream_ = new std::vector<std::complex<double>>();
    for (auto symbol: *input_stream) {
        output_stream_->push_back(symbol + distribution_->operator()(engine_));
    }
}

std::vector<std::complex<double>> *NoiseAdder::getNoisedStream() {
    return output_stream_;
}