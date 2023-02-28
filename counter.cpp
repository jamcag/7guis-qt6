#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Counter");

  QLabel label;
  label.setText("0");
  label.setAlignment(Qt::AlignCenter);

  QPushButton button;
  button.setText("Count");

  QHBoxLayout mainLayout;
  mainLayout.addStretch();
  mainLayout.addWidget(&label);
  mainLayout.addStretch();
  mainLayout.addWidget(&button);
  mainLayout.addStretch();

  window.setLayout(&mainLayout);

  int counter = 0;
  QObject::connect(&button, &QPushButton::clicked, [&](){
    counter++;
    label.setText(QString::number(counter));
  });

  window.show();
  return app.exec();
}