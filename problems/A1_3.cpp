#include "stdafx.h"
#include <iostream>

#define ASSERT(x) if(x == false) std::cout << #x << " was false at " << __LINE__ << std::endl;

struct SquareMatrix
{
	float * m_Elements;
	int m_RowCount;
	int m_ColumnCount;


	SquareMatrix multiply(SquareMatrix & left, SquareMatrix & right)
	{

	}

	SquareMatrix split(int quadrant)
	{
		switch(quadrant)
		{
			case 1: // First Quadrant
			{
				SquareMatrix result(m_RowCount / 2, m_ColumnCount / 2);

				int p = 0;
				for(int i = 0; i < m_RowCount * m_ColumnCount; ++i)
				{
					if(((i % m_RowCount) >= m_RowCount / 2) && ((i % m_RowCount) <= m_RowCount - 1) && (i < m_RowCount * m_ColumnCount / 2 - 1))
					{
						result.m_Elements[p++] = this->m_Elements[i];
					}
				}

				ASSERT(p == (m_RowCount / 2) * (m_ColumnCount / 2));

				return result;
			}
			break;

			case 2: // Second Quadrant
			{
				SquareMatrix result(m_RowCount / 2, m_ColumnCount / 2);

				int p = 0;
				for(int i = 0; i < m_RowCount * m_ColumnCount; ++i)
				{
					if(((i % m_RowCount) >= 0) && ((i % m_RowCount) <= m_RowCount / 2 - 1) && (i <= m_RowCount * m_ColumnCount / 2 - (m_RowCount / 2) + 1));
					{
						result.m_Elements[p++] = this->m_Elements[i];
					}
				}

				ASSERT(p == (m_RowCount / 2) * (m_ColumnCount / 2));

				return result;
			}
			break;

			case 3: // Third Quadrant
			{
				SquareMatrix result(m_RowCount / 2, m_ColumnCount / 2);

				int p = 0;
				for(int i = 0; i < m_RowCount * m_ColumnCount; ++i)
				{
					if(((i % m_RowCount) >= 0) && ((i % m_RowCount) <= m_RowCount / 2 - 1) && (i >= m_RowCount * m_ColumnCount / 2 - 1) && (i <= m_RowCount * m_ColumnCount - m_RowCount + 1));
					{
						result.m_Elements[p++] = this->m_Elements[i];
					}
				}

				ASSERT(p == (m_RowCount / 2) * (m_ColumnCount / 2));

				return result;
			}
			break;

			case 4: // Fourth Quadrant
			{
				SquareMatrix result(m_RowCount / 2, m_ColumnCount / 2);

				int p = 0;
				for(int i = 0; i < m_RowCount * m_ColumnCount; ++i)
				{
					if(((i % m_RowCount) >= 0) && ((i % m_RowCount) <= m_RowCount / 2 - 1) && (i >= m_RowCount * m_ColumnCount / 2 - 1) && (i <= m_RowCount * m_ColumnCount - m_RowCount + 1));
					{
						result.m_Elements[p++] = this->m_Elements[i];
					}
				}

				ASSERT(p == (m_RowCount / 2) * (m_ColumnCount / 2));

				return result;
			}
			break;

			default:
				ASSERT(quadrant > 4);
				break;
		}
	}

	SquareMatrix(int m, int n)
		: m_Elements(new float[m * n]), m_RowCount(m), m_ColumnCount(n)
	{
	}

	SquareMatrix(int * values, int count)
		: m_Elements(new float[sqrt(count)]), m_RowCount(sqrt(count)), m_ColumnCount(sqrt(count))
	{
		for(int i = 0; i < m_RowCount * m_ColumnCount; i++)
		{
			m_Elements[i] = values[i];
		}
	}

	~SquareMatrix()
	{
		delete[] m_Elements;
	}
};

int mainA1_3()
{
	return 0;
}
