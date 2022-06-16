#pragma once
#include <string>
#include <boost/locale.hpp>

using namespace std;

const string wstring2string(const wstring& wstr, string target_code = "GBK");

const wstring string2wstring(const string& str, string source_code = "GBK");