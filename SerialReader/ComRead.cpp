#include <stdio.h>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h> 
#include <atlenc.h>
#include <atlstr.h>
#include <locale>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning (disable : 4996)

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class ComRead {

public:
	static System::Windows::Forms::Form ^m_form;
	static System::Windows::Forms::RichTextBox ^data;
	static System::Windows::Forms::RichTextBox ^status;
	static System::Windows::Forms::ComboBox^  comboBox;
	static bool thread;
	static const char* ComPort;
	static wchar_t* com;
public:
	delegate void StringArgReturningVoidDelegate(String^ text);

	static void ComReadApp(Object^ form)
	{
		m_form = (System::Windows::Forms::Form^)form;
		data = (System::Windows::Forms::RichTextBox^)m_form->Controls->Find((System::String^)"rt_return", true)[0];
		status = (System::Windows::Forms::RichTextBox^)m_form->Controls->Find((System::String^)"rt_status", true)[0];
		comboBox = (System::Windows::Forms::ComboBox^)m_form->Controls->Find((System::String^)"comboBox1", true)[0];

		com = (wchar_t*)malloc(sizeof(wchar_t) * 16);
	}

	static void AppendTextData(String^ text)
	{
		// InvokeRequired required compares the thread ID of the  
		// calling thread to the thread ID of the creating thread.  
		// If these threads are different, it returns true. 
		while (!data) {
			Sleep(1);
		}
		if (data->InvokeRequired)
		{
			StringArgReturningVoidDelegate^ d =
				gcnew StringArgReturningVoidDelegate(&ComRead::AppendTextData);

			data->Invoke(d, gcnew array<Object^> { text });
		}
		else
		{
			data->AppendText(text + "\n");
		}
	}

	static void AppendTextStatus(String^ text)
	{
		// InvokeRequired required compares the thread ID of the  
		// calling thread to the thread ID of the creating thread.  
		// If these threads are different, it returns true. 
		while (!status) {
			Sleep(1);
		}
		if (status->InvokeRequired)
		{
			StringArgReturningVoidDelegate^ d =
				gcnew StringArgReturningVoidDelegate(&ComRead::AppendTextStatus);

			status->Invoke(d, gcnew array<Object^> { text });
		}
		else
		{
			status->AppendText(text + "\n");
		}
	}

	static void SelectComPort()
	{
		// Store serial port paths
		TCHAR lpTargetPath[5000];
		DWORD test;
		
		bool FindPort = 0;
		int j = 0;
		char* comPort;
		comPort = (char*)malloc(sizeof(char) * 32);

		for (int i = 0; i <= 16; i++) // Search COM in range 0 to 255
		{
			CString str;
			str.Format(_T("%d"), i);
			CString ComName = CString("COM") + CString(str); // Converting to COM0, COM1, COM2

			test = QueryDosDevice(ComName, (LPWSTR)lpTargetPath, 5000);

			if (test != 0) // QueryDosDevice returns zero if it didn't find an object
			{
				AppendTextStatus("COM Found: COM" + i);
				snprintf(comPort, 16, "COM%d", i);

				comboBox->Items->Add(gcnew String(comPort));
				FindPort = true;
			}

			if (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				lpTargetPath[10000]; // In case the buffer got filled, increase size of the buffer.
				continue;
			}
		}
		if (!FindPort)
		{
			AppendTextStatus("No Active Ports Found");
		}
		free(comPort);
	}

	static void Write(String^ writeData)
	{
		OVERLAPPED osReader = { 0 };
		DCB _params = { 0 };
		COMMTIMEOUTS timeouts;
		CStringA base64;

		HANDLE hComm;
		DWORD mode, dwBytesWrite;

		timeouts.ReadIntervalTimeout = 500;
		timeouts.ReadTotalTimeoutMultiplier = 500;
		timeouts.ReadTotalTimeoutConstant = 500;
		timeouts.WriteTotalTimeoutMultiplier = 1;
		timeouts.WriteTotalTimeoutConstant = 1;

		char* Buffer;
		int SIZE_BUFFER = writeData->Length + 1;
		int result;

		Buffer = (char*)malloc(sizeof(char) * SIZE_BUFFER);
		if (writeData->Length < SIZE_BUFFER)
			sprintf(Buffer, "%s", writeData);

		hComm = CreateFile(com,
			GENERIC_READ | GENERIC_WRITE,
			0,
			0,
			OPEN_EXISTING, FILE_FLAG_NO_BUFFERING,
			0);

		AppendTextStatus(gcnew String(com));
		if (hComm == INVALID_HANDLE_VALUE)
		{
			AppendTextStatus("Error: COM Invalida!");
		}
		else {
			if (!SetCommTimeouts(hComm, &timeouts)) {
				int g = 0;
				g++;
			}

			mode &= ~ENABLE_PROCESSED_INPUT;
			if (!SetConsoleMode(hComm, mode)) {

			}
			if (!EscapeCommFunction(hComm, CLRDTR)) {

			}
			osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
			
			// Create the overlapped event. Must be closed before exiting
			// to avoid a handle leak.
			_params.BaudRate = 9600;
			GetCommState(hComm, &_params);

			result = WriteFile(hComm, Buffer, SIZE_BUFFER, &dwBytesWrite, NULL);
			if (result != 0) // Read the Keyboard!
			{
				AppendTextStatus("Written message!");
			}
			else
			{
				AppendTextStatus("Error: WriteFile");
				CloseHandle(hComm);
			}
			if (dwBytesWrite) {
				Buffer[dwBytesWrite] = '\0';
				AppendTextData(gcnew String(Buffer));
				AppendTextStatus(gcnew String("Bytes Written: " + dwBytesWrite));
			}
		}
		free(Buffer);

		CloseHandle(hComm);
	}

	static void Read(Object^ form)
	{

		OVERLAPPED osReader = { 0 };
		DCB _params = { 0 };
		COMMTIMEOUTS timeouts;
		CStringA base64;

		HANDLE hComm;
		DWORD mode, dwBytesRead;

		timeouts.ReadIntervalTimeout = 10;
		timeouts.ReadTotalTimeoutMultiplier = 1;
		timeouts.ReadTotalTimeoutConstant = 1;
		timeouts.WriteTotalTimeoutMultiplier = 1;
		timeouts.WriteTotalTimeoutConstant = 1;

		char* Buffer;
		int SIZE_BUFFER = 1024;
		int result;

		Buffer = (char*)malloc(sizeof(char) * SIZE_BUFFER);

		hComm = CreateFile(com,
			GENERIC_READ | GENERIC_WRITE,
			0,
			0,
			OPEN_EXISTING, FILE_FLAG_NO_BUFFERING,
			0);

		AppendTextStatus(gcnew String(com));
		if (hComm == INVALID_HANDLE_VALUE)
		{
			AppendTextStatus("Error: COM Invalida!");
		} else {
			if (!SetCommTimeouts(hComm, &timeouts)) {
				int g = 0;
				g++;
			}

			mode &= ~ENABLE_PROCESSED_INPUT;
			if (!SetConsoleMode(hComm, mode)) {

			}
			if (!EscapeCommFunction(hComm, CLRDTR)) {

			}
			osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
			
			// Create the overlapped event. Must be closed before exiting
			// to avoid a handle leak.
			_params.BaudRate = 9600;
			GetCommState(hComm, &_params);

			AppendTextStatus("Ready to read");
			while (thread)
			{
				if (hComm == INVALID_HANDLE_VALUE)
				{
					AppendTextStatus("Error: COM Disconected!");
					break;
				}

				if (!GetCommState(hComm, &_params))
				{
					hComm = INVALID_HANDLE_VALUE;
					AppendTextStatus("Error: GetCommState");

					break;
				}

				result = ReadFile(hComm, Buffer, SIZE_BUFFER, &dwBytesRead, NULL);
				if (result == 0) // Read the Keyboard!
				{
					AppendTextStatus("Error: ReadFile");
					CloseHandle(hComm);
					break;
				}
				if (dwBytesRead) // If read something...
				{
					// Get read data
					AppendTextStatus("Recieve message!");

					Buffer[dwBytesRead] = '\0';
					AppendTextData(gcnew String(Buffer));
					AppendTextStatus(gcnew String("Bytes Recieved: " + dwBytesRead));
				}
			}
		}
		free(Buffer);

		CloseHandle(hComm);
	}

	static String^ COM;

	static void setThreadRun(bool Thread) { thread = Thread; }
	static void setComPort(String^ COMPORT) 
	{ 
		COM = COMPORT;
		IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalUni(COM);
		wcscpy(com, (wchar_t*)ptrToNativeString.ToPointer());
	}
};