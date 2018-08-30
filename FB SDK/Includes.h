#ifndef __INCLUDES__H_
#define __INCLUDES__H_

#pragma once

#pragma warning (disable:4005) // macro redefinition
#pragma warning (disable:4099) // type name first seen using 'class' now seen using 'struct'
#pragma warning (disable:4244) // '+=' : conversion from 'int' to 'WORD', possible loss of data
#pragma warning (disable:4305) // truncation from 'int' to 'bool'

#pragma comment (lib, "Winmm.lib")
#pragma comment (lib, "d3dx9.lib") // für Chevyyy's ESP wichtig

#include <windows.h>
#include <d3dx9math.h>
#include <map>

#define CONCAT_IMPL(x, y) x##y
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)
#define PAD(SIZE) BYTE MACRO_CONCAT(_pad, __COUNTER__)[SIZE];
#define POINTERCHK( pointer ) ( pointer  && pointer !=0  && HIWORD( pointer ) )

#endif