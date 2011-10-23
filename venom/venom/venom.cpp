/**
  * Copyright (C) KryptonX 2011
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "stdafx.h"
#include "venom.h"
#include "../syringe-irecovery/include/libpois0n.h"
#include "../syringe-irecovery/include/libirecovery.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
LPWSTR _cmd;
void Msg();
const char GetTxt();

#define MAX_LOADSTRING 100

HWND exploit_btn, resetBtn, reset_iBoot, k_exploit, product, model, arg;
HWND command;
HWND cmdBtn;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_VENOM, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	
	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VENOM));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VENOM));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_BTNSHADOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_VENOM);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, TEXT("Venom RC1 by KryptonX"),
                 WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_VISIBLE,
                150, 150, 440, 190, 0, 0, hInstance, 0);

   exploit_btn = CreateWindow(TEXT("button"), TEXT("exploit device"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		            10, 12, 120, 30,        
		             hWnd, (HMENU) 1, NULL, NULL);    

   resetBtn = CreateWindow(TEXT("button"), TEXT("reset usb"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          151, 12, 120, 30,        
		             hWnd, (HMENU) 2, NULL, NULL);  

   reset_iBoot = CreateWindow(TEXT("button"), TEXT("reset"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          290, 12, 120, 30,        
		             hWnd, (HMENU) 3, NULL, NULL);  
 

   product = CreateWindow(TEXT("button"), TEXT("product"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          10, 62, 120, 30,          
		             hWnd, (HMENU) 5, NULL, NULL);  
   EnableWindow(product, FALSE);

   model = CreateWindow(TEXT("button"), TEXT("model"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          151, 62, 120, 30,          
		             hWnd, (HMENU) 4, NULL, NULL);  
   EnableWindow(model, FALSE);

   arg = CreateWindow(TEXT("button"), TEXT("kernel arg"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          290, 62, 120, 30,          
		             hWnd, (HMENU) 6, NULL, NULL);  
   EnableWindow(model, FALSE);


   command = CreateWindow(TEXT("EDIT"), TEXT(""),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		          10, 120, 310, 25,          
		             hWnd, (HMENU) 7, NULL, NULL);  
   //EnableWindow(command, FALSE);

   cmdBtn = CreateWindow(TEXT("button"), TEXT("send"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		        325, 118, 96, 30,          
		             hWnd, (HMENU) 8, NULL, NULL);  
   //EnableWindow(cmdBtn, FALSE);

   

  /* EnableWindow(cmdBtn, FALSE);
   EnableWindow(command, FALSE);*/

  Msg();

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		if (wParam == 1) {
			ShowWindow(exploit_btn, FALSE);			
			exploit_btn = CreateWindow(TEXT("button"), TEXT("running..."),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		             10, 12, 120, 30,       
		             hWnd, (HMENU) 1, NULL, NULL); 
			EnableWindow(exploit_btn, FALSE);
			if (exploit() == 0) {
			ShowWindow(exploit_btn, FALSE);	
			
    exploit_btn = CreateWindow(TEXT("button"), TEXT("exploit device"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		            10, 12, 120, 30,        
		             hWnd, (HMENU) 1, NULL, NULL); 
			} else {
				MessageBox(NULL, TEXT("Your device is not in DFU mode!\n"), TEXT("venom.exe"), 64);
				ShowWindow(exploit_btn, FALSE);	
			
   exploit_btn = CreateWindow(TEXT("button"), TEXT("exploit device"),    
		             WS_VISIBLE | WS_CHILD,
					 /* First 2 Integers are location; last 2 are size */
		            10, 12, 120, 30,        
		             hWnd, (HMENU) 1, NULL, NULL); 
			}	
			
		} else if (wParam == 2)/* Reset Counters */ {  
			irecv_open_attempts(&client, 10);	
			irecv_send_command(client, "0x0");
			irecv_exit();
		} else if (wParam == 3) /* Reset iBoot */ {
			irecv_open_attempts(&client, 10);	
			irecv_send_command(client, "reset");
			irecv_exit();
		} else if (wParam == 4) /* 0x21, 1 */ {
			EnableWindow(model, FALSE);
			irecv_open_attempts(&client, 10);	
	pois0n_init();
	MessageBox(NULL, TEXT("unknown system error\nTry reinstalling this program to fix this error."), TEXT("venom.exe"), MB_ICONSTOP);
	 EnableWindow(model, TRUE);
	irecv_close(client);
		} else if (wParam == 5) /* Device Info */ {	
	EnableWindow(product, FALSE);			
	irecv_open_attempts(&client, 10);	
	pois0n_init();
	MessageBox(NULL, TEXT("unknown system error\nTry reinstalling this program to fix this error."), TEXT("venom.exe"), MB_ICONSTOP);
	 EnableWindow(product, TRUE);
	irecv_close(client);
		} else if (wParam == 6) {
			EnableWindow(arg, FALSE);
			MessageBox(NULL, TEXT("cd214d0968ff4f289c139bdfe30e097ff6225c6c"), TEXT("venom.exe"), 64);
			EnableWindow(arg, TRUE);
		} else if (wParam == 8) {
			irecv_open_attempts(&client, 10);	
			GetWindowText(command, _cmd, 10);
			irecv_send_command(client, "");
			irecv_exit();			
		}
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void Msg(void) {
	MessageBox(NULL, TEXT("Written by: kryptonX (http://github.com/atomic-dev/venom)\n\nSpecial thanks to: posixninja & Chronic-Dev for syringe,\n geohot, westbaer (iRecovery), comex and pod2G."), TEXT("Credits & Special Thanks"),
		MB_OK | 64);
}
