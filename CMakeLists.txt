# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.22)

# 项目信息
project(ClassicalCipher)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/utils
    ${PROJECT_SOURCE_DIR}/include/classical_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/permutation_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/affine_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/caesar_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/monoalphabetic_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/polyalphabetic_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/polyalphabetic_cipher/vigenere_cipher
    ${PROJECT_SOURCE_DIR}/include/classical_cipher/substitution_cipher/shift_cipher
)
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILES)
FILE (GLOB_RECURSE ALL_SOURCES ./src/*.c )
FILE (GLOB_RECURSE ALL_INCLUDES ./include/*.h )
# MESSAGE( STATUS "${ALL_INCLUDES}.")

SET (ALL_SRCS 
	 ${ALL_SOURCES}
	 ${ALL_INCLUDES}
)

# 指定生成目标
add_executable(${CMAKE_PROJECT_NAME} ${ALL_SRCS}) 
