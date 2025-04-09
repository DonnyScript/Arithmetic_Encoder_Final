#ifndef ARITHMETIC_ENCODER_H
#define ARITHMETIC_ENCODER_H

#include <vector>
#include "adaptive_model.h"
#include <fstream>

const int CODE_VALUE_BITS = 16;
const int TOP_VALUE = (1 << CODE_VALUE_BITS) - 1;
const int FIRST_QUARTER = (TOP_VALUE + 1) / 4;
const int HALF = 2 * FIRST_QUARTER;
const int THIRD_QUARTER = 3 * FIRST_QUARTER;

class ArithmeticEncoder {
public:
  ArithmeticEncoder(std::ofstream&);
  void encodeSymbol(int symbol, AdaptiveModel& model);
  std::vector<unsigned char> finish();
  std::vector<unsigned char> output;
  std::ofstream& compressedFile;

private:
  int low, high;
  int pending_bits;
  unsigned char current_byte;
  int bit_count;
  void outputBit(int bit);
  void scale();
};
#endif
