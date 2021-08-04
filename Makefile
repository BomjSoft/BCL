CXX = g++
CXXFLAGS = -fomit-frame-pointer -fexpensive-optimizations -O3 -DUNICODE

SOURCES = Code/Application.cpp \
          Code/Dialogs/OpenFileDialog.cpp Code/Dialogs/SaveFileDialog.cpp \
          Code/Elements/Bitmap.cpp Code/Elements/Brush.cpp Code/Elements/Canvas.cpp Code/Elements/MainMenu.cpp Code/Elements/Pen.cpp \
          Code/Functions/FileOperations.cpp \
          Code/GUI/Button.cpp Code/GUI/CheckBox.cpp Code/GUI/CheckListBox.cpp Code/GUI/ComboBox.cpp Code/GUI/Edit.cpp Code/GUI/Form.cpp Code/GUI/Label.cpp Code/GUI/ListBox.cpp Code/GUI/Memo.cpp Code/GUI/ProgressBar.cpp Code/GUI/RadioButton.cpp Code/GUI/RadioGroup.cpp Code/GUI/TrackBar.cpp \
          Code/ServiceComponents/Component.cpp Code/ServiceComponents/Object.cpp
HEADERS = BCL.h Code/Includes.h Code/Application.h Code/Delegate.h \
          Code/Dialogs/OpenFileDialog.h Code/Dialogs/SaveFileDialog.h \
          Code/Elements/Bitmap.h Code/Elements/Brush.h Code/Elements/Canvas.h Code/Elements/MainMenu.h Code/Elements/Pen.h \
          Code/Functions/FileOperations.h \
          Code/GUI/Button.h Code/GUI/CheckBox.h Code/GUI/CheckListBox.h Code/GUI/ComboBox.h Code/GUI/Edit.h Code/GUI/Form.h Code/GUI/Label.h Code/GUI/ListBox.h Code/GUI/Memo.h Code/GUI/ProgressBar.h Code/GUI/RadioButton.h Code/GUI/RadioGroup.h Code/GUI/TrackBar.h \
          Code/ServiceComponents/Component.h Code/ServiceComponents/Object.h
OBJECTS = Code/Application.o \
          Code/Dialogs/OpenFileDialog.o Code/Dialogs/SaveFileDialog.o \
          Code/Elements/Bitmap.o Code/Elements/Brush.o Code/Elements/Canvas.o Code/Elements/MainMenu.o Code/Elements/Pen.o \
          Code/Functions/FileOperations.o \
          Code/GUI/Button.o Code/GUI/CheckBox.o Code/GUI/CheckListBox.o Code/GUI/ComboBox.o Code/GUI/Edit.o Code/GUI/Form.o Code/GUI/Label.o Code/GUI/ListBox.o Code/GUI/Memo.o Code/GUI/ProgressBar.o Code/GUI/RadioButton.o Code/GUI/RadioGroup.o Code/GUI/TrackBar.o \
          Code/ServiceComponents/Component.o Code/ServiceComponents/Object.o
TARGET = libBCL.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar -r -s $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@