#pragma once

namespace lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(31, 37);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(196, 266);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 337);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 55);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Читати з файла дані";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(291, 250);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 53);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Записати у файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(300, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(191, 48);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Обчислити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(307, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Добуток чисел, кратних 4.";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(300, 202);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 22);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 432);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторна робота №10";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ fname = "numbers.txt"; 
	if (File::Exists(fname)) {
		StreamReader^ reader = File::OpenText(fname); 
		richTextBox1->Clear();
		String^ fileContent = reader->ReadToEnd(); 
		array<String^>^ numbers = fileContent->Split(' '); 
		for (int i = 0; i < numbers->Length; i++) {
			richTextBox1->AppendText(numbers[i] + Environment::NewLine);
		}
		reader->Close();
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int product = 1;
	for (int i = 0; i < richTextBox1->Lines->Length; i++)
	{
		int number;
		if (int::TryParse(richTextBox1->Lines[i], number))
		{
			if (number % 4 == 0)
			{
				product *= number;
			}
		}
	}
	textBox1->Text = Convert::ToString(product); 
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ fileName = "numbers.txt"; 
	StreamWriter^ writer = File::CreateText(fileName); 
	int product = 1;
	for (int i = 0; i < richTextBox1->Lines->Length; i++) {
		int number;
		if (int::TryParse(richTextBox1->Lines[i], number)) {
			if (number % 4 == 0) {
				product *= number;
				writer->WriteLine(number);
			}
		}
	}
	writer->WriteLine("Добуток: " + Convert::ToString(product)); 
	writer->Close();
	MessageBox::Show("Числа, кратні 4, та їх добуток було записано у файл " + fileName);
}
};
}
