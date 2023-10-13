# CMakeList.txt: проект CMake для task_6; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (task_6 "task_6.cpp" "task_6.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task_6 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
