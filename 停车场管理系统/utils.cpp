#include "utils.h"

const string wstring2string(const wstring& wstr, string target_code) {
	string target = boost::locale::conv::from_utf(wstr, target_code);
	return target;
}

const wstring string2wstring(const string& str, string source_code) {
	wstring target = boost::locale::conv::to_utf<wchar_t>(str, source_code);
	return target;
}