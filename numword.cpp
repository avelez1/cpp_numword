//
//  numword.cpp
//  working
//
//  Created by Alexandria Velez on 7/7/20.
//  Copyright © 2020 Alexandria Velez. All rights reserved.
//

#include "numword.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>

using namespace bw;

void numword::appendspace() {
  _final_str += " ";
  
}

void numword::appendhyphen() {
  if (_final_str.length() > 0)
    _final_str += "-";
}

std::string numword::get_hundreds(uint64_t n) {
  std::string str = "";
  int hundreds_digit = floor(n/100);

  if(hundreds_digit > 0) {
    str += _term[hundreds_digit-1] + " " + _hundred;
  }
  else {
    str = str;
  }
  uint64_t remainder = n - hundreds_digit*100;
  if (remainder > 19) {
    //get tens digit name
    
    if (str.length() > 0) {
      str += " ";
    }
    int tens_digit = floor(remainder/10);
    str += _tens[tens_digit-2];
    
    if (remainder == 0) return str;
    //get ones digit name
    
    if (str.length() > 0) {
      str += " ";
    }
    uint64_t o = remainder - tens_digit*10;
    str += _term[o-1];
  }
  else {
    
    if (remainder == 0) return str;
    
    if (str.length() > 0) {
      str += " ";
    }
    str += _term[remainder-1];
  }

  return str;
  
}

const char * numword::words(uint64_t n){
  fflush(stdout);
  _final_str = "";

  uint64_t remainder = n;
  if (n > 999999999999999999) {
    return "error";
  }
  
  if (n == 0) {
    return _zero.c_str();
  }
  
  if (n >= _quadrillion_num) {
    
    int quad_digits = floor(n/_quadrillion_num);
    _final_str += get_hundreds(quad_digits) + " quadrillion";
    
    remainder = remainder - quad_digits*_quadrillion_num;
  }
  
  if (remainder >= _trillion_num) {
    appendspace();
    int trill_digits = floor(remainder/_trillion_num);
    
    _final_str += get_hundreds(trill_digits) + " trillion";
    
    remainder = remainder - trill_digits*_trillion_num;
    
  }
  
  if (remainder >= _billion_num) {
    if (_final_str.length() > 0) {
      _final_str += " ";
    }
    int bill_digits = floor(remainder/_billion_num);
    _final_str += get_hundreds(bill_digits) + " billion";
    
    remainder = remainder - bill_digits*_billion_num;
  }
  
  if (remainder >= _million_num) {
    appendspace();
    int mill_digits = floor(remainder/_million_num);
    _final_str += get_hundreds(mill_digits) + " million";
    
    remainder = remainder - mill_digits*_million_num;
    
  }
  
  if (remainder >= _thousand_num) {
    appendspace();
    int thou_digits = floor(remainder/_thousand_num);
    _final_str += get_hundreds(thou_digits) + " thousand";
    
    remainder = remainder - thou_digits*_thousand_num;
    

  }
  if (_final_str.length() > 0) {
      _final_str += " ";
  }
  _final_str = _final_str + get_hundreds(remainder);
  _final_c_str = _final_str.c_str();

  return _final_c_str;
}

