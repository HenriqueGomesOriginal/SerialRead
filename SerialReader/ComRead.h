#pragma once
#define comRead

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#ifdef comRead

public ref class ComRead
{
public:
	static void ComReadApp(Object^ form);
	static void Read(Object^ form);
	static void AppendTextData(String^ text);
	static void AppendTextStatus(String^ text);
	static void SelectComPort();
	static void setThreadRun(bool Thread);
	static void setComPort(String^ ComPort);
	static void Write(String^ writeData);

public:
	static System::Windows::Forms::Form ^m_form;
	static System::Windows::Forms::RichTextBox ^data;
	static System::Windows::Forms::RichTextBox ^status;
	static System::Windows::Forms::ComboBox^  comboBox;
	static bool thread;
	static const char* ComPort;
	static wchar_t* com;
	static String^ COM;

	delegate void StringArgReturningVoidDelegate(String^ text);
};

#endif