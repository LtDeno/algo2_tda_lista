#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2mm.h"

void crear_y_destruir_lista(){
  lista_t* lista = NULL;
  pa2m_afirmar((lista = lista_crear()), "La lista se crea correctamente");

  pa2m_afirmar((lista_tamanio(lista) == 0), "La cantidad de elementos es cero");
  pa2m_afirmar(lista_vacia(lista), "La lista se encuentra vacia");
  pa2m_afirmar(!lista_primero(lista), "El primer elemento de la lista es NULL");
  pa2m_afirmar(!lista_ultimo(lista), "El ultimo elemento de la lista es NULL");

  lista_iterador_t* listerador = NULL;
  pa2m_afirmar((listerador = lista_iterador_crear(lista)), "El iterador de lista se crea correctamente");

  pa2m_afirmar(!lista_iterador_tiene_siguiente(listerador), "El iterador no tiene siguiente");
  pa2m_afirmar(!lista_iterador_elemento_actual(listerador), "El iterador no tiene elemento actual");

  lista_iterador_destruir(listerador);
  lista_destruir(lista);
}

void operaciones_aplicadas_a_lista_null(){
  char elemento1 = 'a';

  lista_t* lista = NULL;

  pa2m_afirmar((lista_tamanio(lista) == 0), "La cantidad de elementos es cero");
  pa2m_afirmar(lista_vacia(lista), "La lista se encuentra vacia porque no existe");
  pa2m_afirmar(!lista_primero(lista), "Pedir el primer elemento devuelve NULL");
  pa2m_afirmar(!lista_ultimo(lista), "Pedir el primer elemento devuelve NULL");
  pa2m_afirmar(!lista_quitar(lista), "Quitar un elemento devuelve NULL");
  pa2m_afirmar(!lista_quitar_de_posicion(lista, 0), "Quitar un elemento en posicion devuelve NULL");
  pa2m_afirmar(!lista_insertar(lista, &elemento1), "No se puede insertar elemento");
  pa2m_afirmar(!lista_insertar_en_posicion(lista, &elemento1, 0), "No se puede insertar elemento en posicion");
  pa2m_afirmar(!lista_elemento_en_posicion(lista, 0), "No hay elementos en posicion");

  lista_iterador_t* listerador = NULL;
  pa2m_afirmar(!lista_iterador_crear(lista), "El iterador de lista no se crea");
  pa2m_afirmar(!lista_iterador_avanzar(listerador), "No se puede avanzar en un iterador nulo");
  pa2m_afirmar(!lista_iterador_elemento_actual(listerador), "No hay elemento actual en iterador");
  pa2m_afirmar(!lista_iterador_tiene_siguiente(listerador), "No hay siguiente en un iterador nulo");

  lista_iterador_destruir(listerador);
  lista_destruir(lista);  
}

void operaciones_aplicadas_a_lista_vacia(){
  lista_t* lista = lista_crear();
  
  pa2m_afirmar(lista, "La lista se crea correctamente");
  pa2m_afirmar(!lista_elemento_en_posicion(lista, 0), "No hay elemento en posicion 0 de una lista vacia");
  pa2m_afirmar(!lista_elemento_en_posicion(lista, 10), "No hay elemento en posicion 10 de una lista vacia");
  pa2m_afirmar(!lista_quitar_de_posicion(lista, 0), "No se puede quitar elemento de la posicion 0");
  pa2m_afirmar(!lista_quitar_de_posicion(lista, 10), "No se puede quitar elemento de la posicion 10");

  lista_iterador_t* listerador = lista_iterador_crear(lista);

  pa2m_afirmar(listerador, "El iterador de lista se crea correctamente");
  pa2m_afirmar(!lista_iterador_avanzar(listerador), "No se puede avanzar con el iterador en lista vacia");

  lista_iterador_destruir(listerador);
  lista_destruir(lista);
}

void usar_la_lista_correctamente(){
  char elem1 = 'w', elem2 = 'x', elem3 = 'y', elem4 = 'z', elem_aux = 'a';
  printf("\nElemento 1: %c, Elemento 2: %c, Elemento 3: %c, Elemento 4: %c\n", elem1, elem2, elem3, elem4);

  lista_t* lista = lista_crear();

  pa2m_afirmar(lista, "La lista se crea correctamente");
  pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");

  pa2m_afirmar(lista_insertar(lista, &elem2), "Se pudo insertar el elemento 2");
  pa2m_afirmar(lista_insertar(lista, &elem4), "Se pudo insertar el elemento 4");
  pa2m_afirmar(lista_insertar_en_posicion(lista, &elem1, 0), "Se pudo insertar el elemento 1 en la posicion 0");
  pa2m_afirmar(lista_insertar_en_posicion(lista, &elem4, 0), "Se pudo insertar el elemento 4 en la posicion 0");
  pa2m_afirmar(lista_insertar_en_posicion(lista, &elem3, 3), "Se pudo insertar el elemento 3 en la posicion 2");
  pa2m_afirmar(lista_insertar_en_posicion(lista, &elem1, 10000), "Dado una posicion no existente, inserta el elemento 1 al final");

  pa2m_afirmar(!lista_vacia(lista), "La lista no esta vacia");
  pa2m_afirmar((lista_tamanio(lista) == 6), "El tamanio de la lista es 6");
  pa2m_afirmar((lista_elemento_en_posicion(lista, 0) == lista_primero(lista)), "El primer elemento es el mismo que el elemento en posicion 0");
  pa2m_afirmar((lista_elemento_en_posicion(lista, 5) == lista_ultimo(lista)), "El ultimo elemento es le mismo que el elemento en posicion 5");

  pa2m_afirmar((lista_elemento_en_posicion(lista, 0) == &elem4), "El primer elemento es el elemento 4");
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 0);
  printf("Elemento en posicion 0: %c\n", elem_aux);
  pa2m_afirmar((lista_elemento_en_posicion(lista, 1) == &elem1), "El segundo elemento es el elemento 1"); 
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 1);
  printf("Elemento en posicion 1: %c\n", elem_aux);
  pa2m_afirmar((lista_elemento_en_posicion(lista, 2) == &elem2), "El tercer elemento es el elemento 2");
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 2);
  printf("Elemento en posicion 2: %c\n", elem_aux);
  pa2m_afirmar((lista_elemento_en_posicion(lista, 3) == &elem3), "El cuarto elemento es el elemento 3");
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 3);
  printf("Elemento en posicion 3: %c\n", elem_aux);
  pa2m_afirmar((lista_elemento_en_posicion(lista, 4) == &elem4), "El quinto elemento es el elemento 4");
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 4);
  printf("Elemento en posicion 4: %c\n", elem_aux);
  pa2m_afirmar((lista_elemento_en_posicion(lista, 5) == &elem1), "El sexto elemento es el elemento 1");
  elem_aux = *(char*)lista_elemento_en_posicion(lista, 5);
  printf("Elemento en posicion 5: %c\n", elem_aux);

  pa2m_afirmar((lista_quitar(lista) == &elem1), "Se pudo eliminar el elemento 1, que estaba en la ultima posicion");
  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == &elem4), "Se pudo eliminar el elemento 4, que estaba en la primer posicion");
  pa2m_afirmar((lista_primero(lista) == &elem1), "El primer elemento es el elemento 1");
  pa2m_afirmar((lista_ultimo(lista) == &elem4), "El ultimo elemento es el elemento 4");

  lista_iterador_t* listerador = lista_iterador_crear(lista);
  pa2m_afirmar(listerador, "El iterador de lista se crea correctamente");
  pa2m_afirmar((lista_iterador_elemento_actual(listerador) == lista_primero(lista)), "El elemento actual del iterador es el primer elemento");
  pa2m_afirmar(lista_iterador_tiene_siguiente(listerador), "El iterador tiene siguiente elemento");

  int contador = 0;
  while(lista_iterador_avanzar(listerador)){
    contador++;
  }
  pa2m_afirmar((contador == 4), "Se pudo avanzar 4 veces en la lista");
  pa2m_afirmar(!lista_iterador_elemento_actual(listerador), "El elemento actual luego de avanzar al final es NULL");
  pa2m_afirmar(!lista_iterador_tiene_siguiente(listerador), "El iterador de lista no tiene siguiente elemento");

  lista_iterador_destruir(listerador);
  lista_destruir(lista);
}

void uno_que_otro_intento_de_explotar_todo(){
  char elem1 = 'a', elem2 = 'b';

  lista_t* lista = lista_crear();
  pa2m_afirmar(lista, "Se crea la primer lista");
  pa2m_afirmar(lista_insertar_en_posicion(lista, &elem1, 0), "Se pudo insertar un elemento en posicion 0 en lista vacia");
  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == &elem1), "Se pudo quitar el elemento en posicion 0");
  pa2m_afirmar(lista_insertar_en_posicion(lista,&elem2, 10), "Se pudo insertar un nuevo elemento en la posicion 10... 0");
  pa2m_afirmar((lista_quitar_de_posicion(lista, 10) == &elem2), "Se pudo quitar el elemento en posicion 10... 0");
  lista_destruir(lista);


  lista = lista_crear();  
  pa2m_afirmar(lista, "Se crea la segunda lista lista");

  size_t contador = 0;
  while (contador < 10000){
    if(lista_insertar(lista, &elem1)){
      contador++;
    }
  }
  pa2m_afirmar((contador == lista_tamanio(lista)), "Se pudieron insertar 10 mil elementos");

  while (contador < 20000){
    if(lista_insertar(lista, &elem1)){
      contador++;
    }
  }
  pa2m_afirmar((contador == lista_tamanio(lista)), "Se pudieron insertar 10 mil elementos mas");

  for (size_t i = 0 ; i < contador ; i++){
    lista_quitar(lista);
  }
  pa2m_afirmar((lista_tamanio(lista) == 0), "Se pudieron eliminar 20 mil elementos");

  lista_destruir(lista);


  
}

int main() {
  pa2m_nuevo_grupo("Creacion y destruccion de lista");
  crear_y_destruir_lista();

  pa2m_nuevo_grupo("Operar en una lista null");
  operaciones_aplicadas_a_lista_null();

  pa2m_nuevo_grupo("Operar en una lista vacia");
  operaciones_aplicadas_a_lista_vacia();

  pa2m_nuevo_grupo("Hacer uso de la lista sin querer romper todo");
  usar_la_lista_correctamente();

  pa2m_nuevo_grupo("Tratar de romper todo");
  uno_que_otro_intento_de_explotar_todo();

  return pa2m_mostrar_reporte();
}
