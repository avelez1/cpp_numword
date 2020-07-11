//
//  numword.cpp
//  working
//
//  Created by Alexandria Velez on 7/7/20.
//  Copyright © 2020 Alexandria Velez. All rights reserved.
//

#include "numword.hpp"

using namespace bw;

void numword::appendspace() {
  if (!_final_str.empty() && _final_str.back() != ' ')
    _final_str += " ";
}

void numword::appendhyphen() {
  if (_final_str.length() > 0)
    _final_str += "-";
}

void numword::get_hundreds(uint64_t n) {
  int hundreds_digit = floor(n/100);

  if (hundreds_digit > 0) {
    _final_str += _term[hundreds_digit-1] + " " + _hundred;
  }

  uint64_t remainder = n - hundreds_digit*100;
  if (remainder > 19) {
    //get tens digit name
    appendspace();
    int tens_digit = floor(remainder/10);
    _final_str += _tens[tens_digit-2];
    
    //get ones digit name
    appendspace();
    uint64_t o = remainder - tens_digit*10;
    _final_str += _term[o-1];
  }
  else {
    appendspace();
    if (remainder != 0) {
    _final_str += _term[remainder-1];
    }
  }
}

const char * numword::words(uint64_t n){
  _final_str = "";

  uint64_t remainder = n;
  if (n > 999999999999999999)
    return "error";
  
  if (n == 0)
    return _zero.c_str();
  
  if (n >= _quadrillion_num) {
    int quad_digits = floor(n/_quadrillion_num);
    get_hundreds(quad_digits);
    appendspace();
    _final_str += "quadrillion";
    
    remainder = remainder - quad_digits*_quadrillion_num;
  }
  
  if (remainder >= _trillion_num) {
    appendspace();
    int trill_digits = floor(remainder/_trillion_num);
    get_hundreds(trill_digits);
    appendspace();
    _final_str +=  "trillion";
    
    remainder = remainder - trill_digits*_trillion_num;
  }
  
  if (remainder >= _billion_num) {
    appendspace();
    int bill_digits = floor(remainder/_billion_num);
    get_hundreds(bill_digits);
    appendspace();
    _final_str += "billion";
    
    remainder = remainder - bill_digits*_billion_num;
  }
  
  if (remainder >= _million_num) {
    appendspace();
    int mill_digits = floor(remainder/_million_num);
    get_hundreds(mill_digits);
    appendspace();
    _final_str += "million";
    
    remainder = remainder - mill_digits*_million_num;
  }
  
  if (remainder >= _thousand_num) {
    appendspace();
    int thou_digits = floor(remainder/_thousand_num);
    get_hundreds(thou_digits);
    appendspace();
    _final_str +=  "thousand";
    
    remainder = remainder - thou_digits*_thousand_num;
  }
  
  if (remainder > 0) {
    appendspace();
    get_hundreds(remainder);
  }
  
  _final_c_str = _final_str.c_str();

  return _final_c_str;
}

