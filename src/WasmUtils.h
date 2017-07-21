#ifndef _WASM_UTILS
#define _WASM_UTILS

using namespace wasm;
using namespace std;

namespace wdis {
	class util {
	public:
		static FunctionType* resolveFType(Module* m, Name nm) {
			for (int i = 0; i < m->functionTypes.size(); ++i) {
				if (m->functionTypes[i]->name == nm) {
					return m->functionTypes[i].get();
				}
			}
			return nullptr;
		}
		static string tab(int tabTimes) {
			// Util for generating nicer looking C
			string ret;
			for (int i = 0; i < tabTimes; ++i) {
				ret += "\t";
			}
			return ret;
		}
		static string getLiteralValue(Literal* val) {
			int32_t conv_i32;
			int64_t conv_i64;
			float conv_f32;
			double conv_f64;
			switch (val->type) {
				// Convert constant literal type to string
				case WasmType::none:
				case WasmType::unreachable:
					return "0";
					break;
				case WasmType::i32:
					conv_i32 = val->geti32();
					return to_string(conv_i32);
					break;
				case WasmType::i64:
					conv_i64 = val->geti64();
					return to_string(conv_i64);
					break;
				case WasmType::f32:
					conv_f32 = val->getf32();
					return to_string(conv_f32);
					break;
				case WasmType::f64:
					conv_f64 = val->getf64();
					return to_string(conv_f64);
					break;
			}
		}
	};
}; // namespace wdis

#endif // _WASM_UTILS