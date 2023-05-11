cmake_minimum_required(VERSION 3.16)

project(Multimetr VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Qml Quick Core Gui Widgets REQUIRED)

set(SOURCES Sources/TypeApplication.h
            Sources/Shell.h Sources/Shell.cpp
            Sources/Mode.h Sources/Mode.cpp
            Sources/Client.h Sources/Client.cpp
            Sources/GuiApp.h Sources/GuiApp.cpp
            Sources/System.h Sources/System.cpp
            Sources/SocketClient.h Sources/SocketClient.cpp
            Sources/CommunicationCenter.h Sources/CommunicationCenter.cpp
            )

set(SCRIPTS JsScripts/Range.js)

qt_add_resources(RCC_IMG "${CMAKE_CURRENT_SOURCE_DIR}/Image/Img.qrc")

qt_add_resources(RCC_VARIOUS "${CMAKE_CURRENT_SOURCE_DIR}/RCC/Various.qrc")

qt_add_executable(MultimetrApp ${RCC_VARIOUS} ${RCC_IMG} ${SOURCES} main.cpp )

qt_add_qml_module(MultimetrApp
    URI Windows
    VERSION 1.0
    QML_FILES Sources/MainWindow.qml
              Sources/MyButton.qml
              Sources/MyDelayButton.qml
              Sources/MyComboBox.qml
              ${SCRIPTS}
)

set_target_properties(MultimetrApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(MultimetrApp
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(MultimetrApp PRIVATE Qt6::Qml Qt6::Quick Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(MultimetrApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources"
                                                "${CMAKE_CURRENT_SOURCE_DIR}/JsScripts")
