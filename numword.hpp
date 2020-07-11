//
//  numword.hpp
//  working
//
//  Created by Alexandria Velez on 7/7/20.
//  Copyright © 2020 Alexandria Velez. All rights reserved.
//

#ifndef numword_hpp
#define numword_hpp

#include <stdio.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#endif /* numword_hpp */

namespace bw {
  class numword {
    std::string _zero = "zero";
    std::string _term[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string _tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string _hundred = "hundred";
    std::string _thousand = "thousand";
    std::string _million = "million";
    std::string _billion = "billion";
    std::string _trillion = "trillion";
    std::string _quadrillion = "quadrillion";
                            
    uint64_t _quadrillion_num =  1000000000000000;
    uint64_t _trillion_num =     1000000000000;
    uint64_t _billion_num =      1000000000;
    uint64_t _million_num =      1000000;
    uint64_t _thousand_num =     1000;
    
    const char * _final_c_str = "";
    std::string _final_str = "";
    
    
  public:
    void get_hundreds(uint64_t n);
    const char * words(uint64_t n);
    void appendspace();
    void appendhyphen();
  };
}
