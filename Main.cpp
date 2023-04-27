#include <Windows.h>
#include <iomanip>
#include <sstream>
#include "resource.h"
#include "FileReader.cpp"

using namespace std;

BOOL CALLBACK callbackWindow(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow) {
	HWND window = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MAIN), NULL, callbackWindow);
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	ShowWindow(window, cShow);

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		
	}

	return 0;
}

string currencyFormat(double number) {
	std::stringstream stream;
	stream.imbue(std::locale(""));
	stream << std::fixed << std::setprecision(2) << number;
	string currency = stream.str();
	stream.clear();
	stream.flush();
	return stream.str();
}

wchar_t* parseString(string row) {
	int wchars_num = MultiByteToWideChar(CP_UTF8, 0, row.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, row.c_str(), -1, wstr, wchars_num);
	return wstr;
}

BOOL CALLBACK callbackWindow(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_INITDIALOG: {
			FileReader reader;
			Empleado* employees = reader.read();
			HWND table = GetDlgItem(window, T_EMPLEADOS);
			int under5k = 0, ge5k = 0;
			for (int i = 0; i < 15; i++) {
				Empleado employee = employees[i];
				if (employee.getNombre().length() > 0 && employee.getSueldo() > 0) {
					if (employee.getSueldo() < 5000) {
						under5k++;
					}
					else {
						ge5k++;
					}
					string nombre = employee.getNombre();
					string sueldo = currencyFormat(employee.getSueldo());
					string sueldoAumento = currencyFormat(employee.getSueldoAumento());
					string row = " " + nombre + "\t\t  $ " + sueldo + "\t->\t$ "+ sueldoAumento;
					wchar_t* wstr = parseString(row);

					SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr);
					delete[] wstr;
				}
			}
			wchar_t* wstr = parseString("            -------------------------  T  O  T  A  L  E  S  -------------------------");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr);
			wstr = parseString("\t HAY " + to_string(under5k) + " EMPLEADOS QUE GANAN MENOS DE $ 5, 000.00");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr);
			wstr = parseString("\t HAY " + to_string(ge5k) + " EMPLEADOS QUE GANAN $ 5, 000.00 O MAS");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr);
			delete[] wstr;

		} break;
		case WM_COMMAND: {
			/*if (LOWORD(wParam) == BTN_LOAD && HIWORD(wParam) == BN_CLICKED) {
				FileReader reader;
				Empleado* employees = reader.read();
				HWND table = GetDlgItem(window, T_EMPLEADOS);
				for (int i = 0; i < 15; i++) {
					string nombre = employees[i].getNombre();
					std::stringstream stream;
					stream << std::fixed << std::setprecision(2) << employees[i].getSueldo();
					string sueldo = stream.str();
					string row = " " + nombre + "\t\t  $" + sueldo;
					int wchars_num = MultiByteToWideChar(CP_UTF8, 0, row.c_str(), -1, NULL, 0);
					wchar_t* wstr = new wchar_t[wchars_num];
					MultiByteToWideChar(CP_UTF8, 0, row.c_str(), -1, wstr, wchars_num);

					SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr);
					delete[] wstr;
				}
				
				
			}*/
		} break;

		case WM_CLOSE: DestroyWindow(window); break;
		case WM_DESTROY: PostQuitMessage(117); break;

		default: break;
	}
	return false;
}
