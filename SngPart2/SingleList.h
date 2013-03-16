/*****************************************************************************
 Author: Erno Pakarinen
 Date: 22.8.2009
  
 Description:
	A template for abstract singly linked list. List holds pointers to the
    given type. List also takes ownership of the items.
 
 Usage:
	To create a concrete list of certain type, e.g. string, use

		typedef SingleList< string > StringList;
 
		StringList myStringList = new StringList();
		myStringList.Insert( new string("Stringulation") );
 
	To iterate through the list either use the direct methods of the SingleList
	concrete type or create a iterator using:
 
		typedef SingeListIterator< string > StringListIterator;
 
		StringListIterator stringIter( myStringList );
		string* str;
		while( ( str = stringIter.next() ) != NULL ) { 
			... 
		}
 
 ******************************************************************************/

#pragma once

#include <stdlib.h>

/**
 * Defines a template for list node which holds a pointer to the next node
 * and a pointer to the actual data item.
 */
template< class T >
class SingleListNode
{	
public:
	/// Default constructor. Sets the object to NULL
	SingleListNode();

	/**
	 * Constructor which takes object and the old head node pointer
	 * @param obj pointer to the object
	 * @param oldHead pointer to the current head node
	 * @notice Node takes ownership of the given object
	 */
	SingleListNode( T* obj, SingleListNode< T >* oldHead );

	/// Destructor
	virtual ~SingleListNode();

public: // Data
	/// Pointer to the next node
	SingleListNode< T >* next;
	/// Own: Object
	T* object;
};

// ---------------------------------------------------------------------------

/**
 * Defines a template for a singly linked list. 
 */
template< class T >
class SingleList
{
public: // Constructor(s) and destructors 
	/// Default constructor, makes an empty list
	SingleList();

	/// Destructor
	virtual ~SingleList();

public: 
	/// Clear the list deallocating all the objects
	void clear();
	/**
	 * Insert a new object to the start of the list.
	 * @param object Pointer to the object to be inserted
	 * @notice Takes ownership of the given object!
	 */
	bool insert( T* object );

	/**
	 * Remove a given object from the list
	 * @param object pointer to the object to be removed
	 */
	void remove( T* object );

	/**
	 * Return the current size of the list
	 * (speed improvement: store the size in a variable)
	 * @return the number of elements in this list
	 */
	int size() const;

	/**
	 * Return a pointer to the head node of this list
	 * Used by the iterator. 
	 * @return a pointer to the head node 
	 */
	SingleListNode< T >* headnode() const;

private:
	/// Owned: First node
	SingleListNode< T >* head;
};

// ---------------------------------------------------------------------------

/**
 * Defines a list iterator which can be used to iterate through a list
 */
template< class T >
class SingleListIterator
{
public: // Constructor
	/**
	 * Constructs a iterator for the given list
	 * @param singlelist The list which will be iterated
	 */
	SingleListIterator( SingleList< T >* singlelist );

public: // New methods
	/**
	 * Reset the iterator to the first element in the list and return it
	 * @return the first element in the list
	 */
	T* reset();

	/**
	 * return the current object and traverse to the next
	 * @return a pointer to the object. NULL means the end of the list
	 */
	T* next();

	/**
	 * Get te current element
	 * @return a pointer to the object
	 */
	T* get() const;

private:
	/// Reference: Current list node
	SingleListNode< T >* current;
	/// Reference: The list to be iterated
	SingleList< T >* list;
};

// ---------------------------------------------------------------------------

template< class T >
SingleListIterator< T >::SingleListIterator( SingleList< T >* singlelist )
{
	current = singlelist->headnode();
	list = singlelist;
}

template< class T >
T* SingleListIterator< T >::reset()
{
	current = list->headnode();
	return current->object;
}

template< class T >
T* SingleListIterator< T >::next()
{
	T* item = get();
	if( current != NULL  )
	{
		current = current->next;
	}
	return item;
}

template< class T >
T* SingleListIterator< T >::get() const
{
	T* res = NULL;
	if( current )
	{
		res = current->object;
	}

	return res;
}

// ---------------------------------------------------------------------------

template< class T >
SingleListNode< T >::SingleListNode( T* obj, SingleListNode< T >* oldHead ) 
	: next( oldHead ), object( obj )
{
}

template< class T >
SingleListNode< T >::SingleListNode()
{
	object = NULL;
}

template< class T >
SingleListNode< T >::~SingleListNode()
{
	delete object;
}


// ---------------------------------------------------------------------------
template< class T >
SingleList< T >::SingleList(void)
{
	head = NULL;
}

template< class T >
SingleList< T >::~SingleList(void)
{
	clear();
}

template< class T >
void SingleList< T >::clear()
{
	SingleListNode< T >* node = head;
	while( node != NULL ) 
	{
		SingleListNode< T >* oldNode = node;
		node = node->next;
		delete oldNode;
	}
}

template< class T >
bool SingleList< T >::insert( T* object )
{
	SingleListNode< T >* newNode = new SingleListNode< T >( object, head );
	head = ( newNode ) ? newNode : head;
	return ( newNode != NULL );
}

template< class T >
void SingleList< T >::remove( T* object )
{
	// Not implemented yet
}

template< class T >
int SingleList< T >::size() const
{
	SingleListNode< T >* node = head;
	int count = 0;
	while( node != NULL ) 
	{
		++count;
		node = node->next;
	}
	return count;
}

template< class T >
SingleListNode< T >* SingleList< T >::headnode() const
{
	return head;
}
