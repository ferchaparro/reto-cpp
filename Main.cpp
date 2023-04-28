#include <Windows.h>
#include <vector>
#include <memory>
#include "resource.h"
#include "EmployeeService.cpp"

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

BOOL CALLBACK callbackWindow(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_INITDIALOG: {
			static unique_ptr<EmployeeService> service = make_unique<EmployeeService>();
			vector<Employee> employees = service->getEmployeesData();
			HWND table = GetDlgItem(window, T_EMPLEADOS);
			int under5k = 0;
			for (auto& employee : employees) {
				if (employee.getName().length() > 0 && employee.getSalary() > 0) {
					if (employee.getSalary() < 5000) {
						under5k++;
					}
					string name = employee.getName();
					string salary = service->currencyFormat(employee.getSalary());
					string newSalary = service->currencyFormat(employee.getNewSalary());
					string row = " " + name + "\t\t  $ " + salary + "\t->\t$ "+ newSalary;
				
					wstring wstr = service->parseString(row);

					SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr.c_str());
				}
			}
			wstring wstr = service->parseString("            -------------------------  T  O  T  A  L  E  S  -------------------------");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr.c_str());
			wstr = service->parseString("\t HAY " + to_string(under5k) + " EMPLEADOS QUE GANAN MENOS DE $ 5, 000.00");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr.c_str());
			wstr = service->parseString("\t HAY " + to_string(employees.size()-under5k) + " EMPLEADOS QUE GANAN $ 5, 000.00 O MAS");
			SendMessage(table, LB_ADDSTRING, NULL, (LPARAM)wstr.c_str());
		} break;
		case WM_COMMAND: {

		} break;

		case WM_CLOSE: DestroyWindow(window); break;
		case WM_DESTROY: PostQuitMessage(117); break;

		default: break;
	}
	return false;
}
