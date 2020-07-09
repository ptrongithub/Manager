cmake_minimum_required(VERSION 3.16)
project(Manager)
message(STATUS "MSVC19")

set(PREFS Prefs)

set(CMAKE_CXX_STANDARD 17)

set(SRC_MAIN
	src/main.h src/main.cpp
	)
set(SRC_PREFS
	src/_main/main_prefs.h src/_main/main_prefs.cpp
	)

set(SRC_FILES
#	main.h main.cpp
	src/db.inc.h
	src/includes.h
	src/ptree.inc.h
	src/views.inc.h
	src/Database/helpers/dbU.h src/Database/helpers/dbU.cpp
	src/Preferences/models/mPrefs.h src/Preferences/models/mPrefs.cpp
#	src/Tools/views/ManualQuery.h src/Tools/views/ManualQuery.cpp
	src/UAC/controllers/UACcDefault.h src/UAC/controllers/UACcDefault.cpp
	src/UAC/models/UACmUsers.h src/UAC/models/UACmUsers.cpp
	src/UAC/views/UACvLogin.h src/UAC/views/UACvLogin.cpp


#	src/Application/views/manager.h src/Application/views/manager.cpp # Main Window
#	src/Preferences/Database/views/ConfigDatabaseConn.h src/Preferences/Database/views/ConfigDatabaseConn.cpp
#	src/Preferences/helpers/PrefsData.h src/Preferences/helpers/PrefsData.cpp
#	src/Preferences/views/Preferences.h src/Preferences/views/Preferences.cpp


	)

# External Library Root Locations
set(BOOST E:/cpp/Lib/boost) # ${BOOST}
#set(MARIADB E:/cpp/Lib/MariaDB) # ${MARIADB}
set(MYSQL E:/cpp/Lib/MySQL) # ${MYSQL}
#set(POSTGRESQL E:/cpp/lib/PostgreSQL) # ${POSTGRESQL}
set(SOCI E:/cpp/lib/soci/soci-4.0.0) # ${SOCI}
set(WXWIDGETS E:/cpp/Lib/wxWidgets/3.1.3/msw) # ${WXWIDGETS}

set(BOOST_INCLUDE
	${BOOST}
	${BOOST}/include
	)
set(BOOST_LIB
	${BOOST}/lib
	)
set(BOOST_LIBS
	)

set(MYSQL_INCLUDE
	${MYSQL}/msvcd
	${MYSQL}/msvcd/include
	${MYSQL}/msvcd/lib64
	${MYSQL}/msvcd/lib64/debug
	${MYSQL}/c/include
	)
set(MYSQL_LIB
	${MYSQL}/msvcd/lib64
	${MYSQL}/msvcd/lib64/debug
	${MYSQL}/msvcd/lib64/vs14
	${MYSQL}/msvcd/lib64/vs14/debug
	${MYSQL}/c/lib
	)
set(MYSQL_LIBS
	mysqlcppconn.lib
	mysqlcppconn8.lib
	)

set(SOCI_LIBS
	${SOCI}/build/lib/Debug/libsoci_core_4_0.lib
	${SOCI}/build/lib/Debug/libsoci_mysql_4_0.lib
	${SOCI}/build/lib/Debug/soci_core_4_0.lib
	${SOCI}/build/lib/Debug/soci_mysql_4_0.lib
	)

add_definitions(-DWXUSINGDLL=1)
add_definitions(-DwxMSVC_VERSION_AUTO=1)
add_definitions(-DwxMSVC_VERSION_ABI_COMPAT=1)
add_definitions(-DUNICODE=1)
add_definitions(-D_UNICODE=1)
#add_definitions(-D__ROOT__=${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
	.
	${PROJECT_SOURCE_DIR}
#	includes
	${WXWIDGETS}
	${WXWIDGETS}/include
	${WXWIDGETS}/include/msvc
	${WXWIDGETS}/lib/vc14x_x64_dll
	${WXWIDGETS}/lib/vc14x_x64_dll/mswud
	${BOOST_INCLUDE}
	${MYSQL_INCLUDE}
	${MYSQL_INCLUDE}/mysqlx
	${SOCI}/include
	${SOCI}/build/include
)

link_directories(
	${WXWIDGETS}/lib/vc14x_x64_dll
	${BOOST_LIB}
	${MYSQL_LIB}
	${SOCI}/build/lib/Debug
)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /P")
add_executable(${PROJECT_NAME} ${SRC_MAIN} ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
	LINK_FLAGS /SUBSYSTEM:WINDOWS
	#	LINK_FLAGS /MDd
	)
target_link_libraries(${PROJECT_NAME}
	${MYSQL_LIBS}
	${SOCI_LIBS}
	)

add_executable(${PREFS} ${SRC_PREFS} ${SRC_FILES})
set_target_properties(${PREFS} PROPERTIES
	LINK_FLAGS /SUBSYSTEM:WINDOWS
	)
target_link_libraries(${PREFS}
	${MYSQL_LIBS}
	${SOCI_LIBS}
	)


##message(STATUS ${Boost_INCLUDE_DIR})
#set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "E:/cpp/Lib/boost")
##set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "E:/cpp/Lib/boost")
#set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "E:/cpp/Lib/boost/lib")
#set(BOOST_ROOT E:/cpp/Lib/boost)
#FIND_PACKAGE(Boost)
#message(STATUS ${Boost_FOUND})