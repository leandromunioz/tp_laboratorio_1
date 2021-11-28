/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); // crea uno nuevo(constructor)
int ll_len(LinkedList* this); //devuelve la cantidad de elementos en la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); // agrega uno (alta)
void* ll_get(LinkedList* this, int index); //obtener uno
int ll_set(LinkedList* this, int index,void* pElement); //modificar uno
int ll_remove(LinkedList* this,int index);// borrar uno
int ll_clear(LinkedList* this);// vacia la lista
int ll_deleteLinkedList(LinkedList* this); //elimina la lista
int ll_indexOf(LinkedList* this, void* pElement);//indice del elemento. (momentanea, cambia si se ordena).
int ll_isEmpty(LinkedList* this); // me dice si hay uno cargado o no.
int ll_push(LinkedList* this, int index, void* pElement); // pone uno en la posicion que indiques
void* ll_pop(LinkedList* this,int index); // elimina el elemento y me devuelve los datos de los que se elimino.
int ll_contains(LinkedList* this, void* pElement); // me dice si el elemento esta en la lista o no.
int ll_containsAll(LinkedList* this,LinkedList* this2);// me dice si una lista esta dentro de la otroa lista.
LinkedList* ll_subList(LinkedList* this,int from,int to);// crea una sublista desde las posiciones que le de
LinkedList* ll_clone(LinkedList* this);// clona una lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //ordena segun la funcion de ordenamiento que le pasemos.
