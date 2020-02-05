#pragma once
#include "ComRead.h"

namespace SerialReader {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		bool Read;
		Thread^ SerialThread;
	public: System::Windows::Forms::RichTextBox^  rt_return;


	private: System::Windows::Forms::Button^  button5;
	public:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	public: System::Windows::Forms::RichTextBox^  rt_status;
	private:

	public:





		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ComRead::ComReadApp(this);


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->rt_return = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->rt_status = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(177, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Serial port select";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownHeight = 120;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Location = System::Drawing::Point(12, 55);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(198, 24);
			this->comboBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(135, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Refresh";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Read";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// rt_return
			// 
			this->rt_return->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rt_return->CausesValidation = false;
			this->rt_return->Cursor = System::Windows::Forms::Cursors::Default;
			this->rt_return->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rt_return->Location = System::Drawing::Point(12, 172);
			this->rt_return->Name = L"rt_return";
			this->rt_return->ReadOnly = true;
			this->rt_return->Size = System::Drawing::Size(486, 242);
			this->rt_return->TabIndex = 0;
			this->rt_return->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(247, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Status";
			// 
			// rt_status
			// 
			this->rt_status->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rt_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rt_status->Cursor = System::Windows::Forms::Cursors::Default;
			this->rt_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rt_status->ForeColor = System::Drawing::SystemColors::WindowText;
			this->rt_status->Location = System::Drawing::Point(252, 41);
			this->rt_status->Name = L"rt_status";
			this->rt_status->ReadOnly = true;
			this->rt_status->Size = System::Drawing::Size(246, 96);
			this->rt_status->TabIndex = 6;
			this->rt_status->Text = L"";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(12, 143);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Write";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(198, 20);
			this->textBox1->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(12, 420);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Clear";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(252, 143);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(510, 456);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->rt_status);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->rt_return);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"SerialReader";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->Items->Clear();
		ComRead::SelectComPort();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Read) 
	{
		button2->Text = "Read";
		ComRead::setThreadRun(false);
		Read = false;
	}
	else {
		if (comboBox1->SelectedIndex == -1) {
			rt_status->ForeColor = System::Drawing::Color::Red;
			rt_status->AppendText("Error: COM port not selected\n");
			rt_status->ForeColor = System::Drawing::Color::Black;
		}
		else {
			ComRead::setComPort(comboBox1->SelectedItem->ToString());
			ComRead::setThreadRun(true);

			SerialThread = gcnew Thread(gcnew ParameterizedThreadStart(&ComRead::Read));
			SerialThread->IsBackground = true;
			SerialThread->Name = "COM Thread";

			SerialThread->Start(this);
			button2->Text = "Stop";

			Read = true;
		}
	}
}
private: System::Void rt_return_TextChanged(System::Object^ sender, EventArgs e) {
	// set the current caret position to the end
	rt_return->SelectionStart = rt_return->Text->Length;
	// scroll it automatically
	rt_return->ScrollToCaret();
}
private: System::Void rt_status_TextChanged(System::Object^ sender, EventArgs e) {
	// set the current caret position to the end
	rt_status->SelectionStart = rt_status->Text->Length;
	// scroll it automatically
	rt_status->ScrollToCaret();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	rt_status->Clear();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	rt_return->Clear();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (comboBox1->SelectedIndex == -1) {
		rt_status->ForeColor = System::Drawing::Color::Red;
		rt_status->AppendText("Error: COM port not selected\n");
		rt_status->ForeColor = System::Drawing::Color::Black;
	} else if (Read) {
		rt_status->AppendText("Error: You need stop read for write\n");
	} else {
		ComRead::setComPort(comboBox1->SelectedItem->ToString());
		ComRead::Write(textBox1->Text);
	}
}
};
}
