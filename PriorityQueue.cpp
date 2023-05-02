#include "PriorityQueue.h"

int min(const int& a, const int& b)
{
    if (a < b) return a;
    else return b;
}

PriorityQueue::PriorityQueue()
{
    connections = nullptr;
    size = 0;
    maxSize = 1;
}

int PriorityQueue::Size() const
{
    return size;
}

const int& PriorityQueue::Parent(const int& index) const
{
    return (index + 1) / 2 - 1;
}

const int& PriorityQueue::Left(const int& index) const
{
    return 2 * index + 1;
}

const int& PriorityQueue::Right(const int& index) const
{
    return 2 * index + 2;
}

void PriorityQueue::Swap(const int& index1, const int& index2)
{
    Connection tmp = connections[index1];
    connections[index1] = connections[index2];
    connections[index2] = tmp;
}

void PriorityQueue::AddBuffer()
{
    maxSize *= 2;
    Connection* tmp = connections;

    this->connections = new Connection[maxSize];
    for (int i = 0; i < size; i++)
    {
        this->connections[i] = tmp[i];
    }
    delete[] tmp;
}

void PriorityQueue::Enqueue(const Connection& newConnection)
{
    int priority = newConnection.GetLength();

    //std::cout << "enqueueing connection" << std::endl;
    if (size == 0)
    {
        connections = new Connection[1];
        connections[0] = newConnection;
        size++;
        return;
    }
    else if(size == maxSize)
    {
        AddBuffer();
    }
    connections[size] = newConnection;
    size += 1;

    int index = size - 1;
    while (index != 0 && connections[Parent(index)].GetLength() > priority)
    {
        int parentIndex = Parent(index);
        Swap(parentIndex, index);
        index = parentIndex;
    }
}

void PriorityQueue::Dequeue()
{
    Swap(0, size-1);
    size--;
    Heapify(0);
}

void PriorityQueue::Heapify(const int& index)
{
    if (Left(index) >= size) return;

    int leftChildIndex = Left(index);
    int rightChildIndex = Right(index);
    if (Right(index) >= size) rightChildIndex = leftChildIndex;

    int minConnection = min(min(connections[leftChildIndex].GetLength(), connections[rightChildIndex].GetLength()), connections[index].GetLength());

    if (minConnection == connections[index].GetLength()) return;
    if (minConnection == connections[leftChildIndex].GetLength())
    {
        Swap(leftChildIndex, index);
        Heapify(leftChildIndex);
    }
    else
    {
        Swap(rightChildIndex, index);
        Heapify(rightChildIndex);
    }
}

const Connection& PriorityQueue::Peek()
{
    return connections[0];
}
