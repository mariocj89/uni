/**
* \file testprision.cpp
* \brief Implementacion de los juegos de prueba de la clase prision
* \date 04-05-09
* \author
*   \b Nombre Mario \n
*   \b Apellidos Corchero Jiménez \n
*   \b Asignatura Laboratorio de Programacion II \n
*   \b Grupo 9 \n
*   \b Entrega 2
*   \b Curso 2º
*/

#include <gtest/gtest.h>
#include "prision.h"

TEST(TestPrision,MetodosBasicos){
  Planta *p=new Planta(0,10,10,0,99,30,5);
  EXPECT_EQ(0,Prision::get_instancia()->get_numero_plantas());
  Prision::get_instancia()->set_planta(p);
  EXPECT_EQ(1,Prision::get_instancia()->get_numero_plantas());
  EXPECT_EQ(0,Prision::get_instancia()->get_planta(5));
  EXPECT_EQ(p,Prision::get_instancia()->get_planta(0));
  EXPECT_EQ(0,Prision::get_instancia()->ocupacion_celda(0,0));
  EXPECT_EQ(10,Prision::get_instancia()->get_alto_planta(0));
  EXPECT_EQ(10,Prision::get_instancia()->get_ancho_planta(0));
  EXPECT_EQ(0,Prision::get_instancia()->get_entrada_panta(0));
  EXPECT_EQ(99,Prision::get_instancia()->get_salida_planta(0));
  EXPECT_EQ(0,Prision::get_instancia()->get_turno());


  delete Prision::get_instancia();

}
