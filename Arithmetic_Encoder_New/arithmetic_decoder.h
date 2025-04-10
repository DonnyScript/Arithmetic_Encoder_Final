#ifndef ARITHMETIC_DECODER_H
#define ARITHMETIC_DECODER_H

#include <fstream>
#include "adaptive_model.h"

class ArithmeticDecoder
{
  public:
    ArithmeticDecoder(std::ifstream& compressedFile);
    int decodeSymbol(AdaptiveModel& model);

  private:
    std::ifstream& input_bytes;
    size_t bit_index;
    int low, high, code;
    int readBit();
};

#endif
