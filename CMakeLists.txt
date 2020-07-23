cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
	project(cmd VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(cmd VERSION 0.0.1)
endif()

set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

add_executable(cmd main.cpp "lib/Logger.cpp" "lib/Reader.cpp")

set_target_properties(cmd PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)

if(MSVC)
	target_compile_options(cmd PRIVATE
		/W4
	)
else()
	target_compile_options(cmd PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()

install(TARGETS cmd RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()