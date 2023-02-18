#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *node = new ListNode(value);
    node->next = head->next;
    head->next = node;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *node = new ListNode(value);
    ListNode<T> *n_ptr = head;
    while(n_ptr->next != nullptr)
    {
        n_ptr = n_ptr->next;
    }
    n_ptr->next = node;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    if(num_of_element > 0 && head->next != nullptr)
    {
        ListNode<T> *n_ptr = head;
        while (n_ptr->next->next != nullptr) {
            n_ptr = n_ptr->next;
        }
        ListNode<T> *k_ptr = n_ptr->next;
        n_ptr->next = nullptr;
        delete k_ptr;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::pop_front() {
    if(num_of_element > 0 && head->next != nullptr) {
        ListNode<T> *n_ptr = head->next;
        head->next = n_ptr->next;
        delete n_ptr;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::remove(T &val) {
    ListNode<T> *n_ptr = head->next;
    ListNode<T> *pre_ptr = head;
    while(n_ptr != nullptr)
    {

        if(n_ptr->val == val)
        {
            ListNode<T> *delete_node = n_ptr;
            pre_ptr->next = n_ptr->next;
            n_ptr = n_ptr->next;
            delete delete_node;
            num_of_element--;
        }
        else
        {
            n_ptr = n_ptr->next;
            pre_ptr = pre_ptr->next;
        }


    }
    // node with val as value is not found.
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    ListNode<T> *n_ptr = head->next;
    ListNode<T> *pre_ptr = head;
    auto other_list = (LinkedList<T> &) ot;
    //base case:
    if(other_list.num_of_element < 1 || other_list.head->next == nullptr)
    {
        return;
    }
    else if(num_of_element < 1 || head->next == nullptr)
    {
        while(other_list.head->next != nullptr)
        {
            T value = other_list.head->next->val;
            other_list.pop_front();
            push_back(value);
        }
         return;
    }

    while(n_ptr != nullptr && other_list.head->next != nullptr)
    {
        ListNode<T> *ot_ptr = other_list.head->next;
        if(ot_ptr->val <= n_ptr->val)
        {
            T value = ot_ptr->val;
            other_list.pop_front();
            ListNode<T> *new_node = new ListNode<T>(value);
            pre_ptr->next = new_node;
            new_node->next = n_ptr;
            pre_ptr = pre_ptr->next;
            num_of_element++;
        }
        else
        {
            n_ptr = n_ptr->next;
            pre_ptr = pre_ptr->next;
        }
    }
    if(n_ptr == nullptr)
    {
        while(other_list.head->next != nullptr)
        {
            T value = other_list.head->next->val;
            other_list.pop_front();
            push_back(value);
        }
    }
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    ListNode<T> *last_node = head->next;
    while(last_node->next != nullptr)
    {
        last_node = last_node->next;
    }
    while(head->next != last_node)
    {
    ListNode<T> *pre_node = head->next;
    while(pre_node->next != last_node)
    {
        pre_node = pre_node->next;
    }
        T value = pre_node->val;
        remove(value);
        push_back(value);
    }


}