#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDoubleValidator>

#include <iostream>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("TempConv");

  QLabel celsiusLabel;
  celsiusLabel.setText("Celsius = ");
  celsiusLabel.setAlignment(Qt::AlignCenter);
  QLineEdit celsiusInput;
  celsiusInput.setText("20");
  QDoubleValidator celsiusVal;
  celsiusInput.setValidator(&celsiusVal);

  QLabel fahrenheitLabel;
  fahrenheitLabel.setText("Fahrenheit");
  fahrenheitLabel.setAlignment(Qt::AlignCenter);
  QLineEdit fahrenheitInput;
  QDoubleValidator fahrenheitVal;
  fahrenheitInput.setValidator(&fahrenheitVal);

  QHBoxLayout mainLayout;
  mainLayout.addStretch();
  mainLayout.addWidget(&celsiusInput);
  mainLayout.addWidget(&celsiusLabel);
  mainLayout.addWidget(&fahrenheitInput);
  mainLayout.addWidget(&fahrenheitLabel);
  mainLayout.addStretch();

  window.setLayout(&mainLayout);

  QObject::connect(&celsiusInput, &QLineEdit::textEdited, [&]() {
    std::cout << "," << std::flush;
    const double celsius = celsiusInput.text().toDouble();
    const double fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;
    fahrenheitInput.setText(QString::number(fahrenheit));
  });

  QObject::connect(&fahrenheitInput, &QLineEdit::textEdited, [&]() {
    std::cout << "." << std::flush;
    const double fahrenheit = fahrenheitInput.text().toDouble();
    std::cout << "fahrenheit=" << fahrenheit << std::endl;
    const double celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
    std::cout << "celsius=" << celsius << std::endl;
    celsiusInput.setText(QString::number(celsius));
  });

  window.show();
  return app.exec();
}