#include <stdio.h>

typedef struct
{
	int h, w, d;
} Present;

int max(int a, int b)
{
	return (a < b) ? b : a;
}

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

int main()
{
	int presents;

	scanf("%d", &presents);

	Present arr[presents];

	for (int p = 0; p < presents; p++)
		scanf("%d %d %d", &arr[p].h, &arr[p].w, &arr[p].d);

	Present rot[3 * presents];

	int index = 0;
	for (int i = 0; i < presents; i++)
	{
		// Copy the original box
		rot[index].h = arr[i].h;
		rot[index].d = max(arr[i].d, arr[i].w);
		rot[index].w = min(arr[i].d, arr[i].w);
		index++;

		// First rotation of box
		rot[index].h = arr[i].w;
		rot[index].d = max(arr[i].h, arr[i].d);
		rot[index].w = min(arr[i].h, arr[i].d);
		index++;

		// Second rotation of box
		rot[index].h = arr[i].d;
		rot[index].d = max(arr[i].h, arr[i].w);
		rot[index].w = min(arr[i].h, arr[i].w);
		index++;
	}

	presents = 3 * presents;

	int msh[presents];
	for (int i = 0; i < presents; i++ )
		msh[i] = rot[i].h;
	
	int used_all = 1;

	int olds_h[3];

	for (int i = 3; i <= presents; i++)
	{
		if (i % 3 == 0 && i / 3 >= 2)
		{
			int equal = 0;
			for (int k = 0; k < 3 && (i+k-3) < presents; k++)
				equal |= (olds_h[k] != msh[i+k-3]);

			used_all = equal;

			if (!used_all || i == presents)
				break;
		}

		if (i % 3 == 0)
		{
			for (int k = 0; k < 3 && (i+k) < presents; k++)
				olds_h[k] = msh[i+k];
		}

		for (int j = (i - (i % 3)) - 3; j < (i - (i % 3)); j++)
			if (rot[i].w <= rot[j].w &&  rot[i].d <= rot[j].d && msh[i] < msh[j] + rot[i].h)
				msh[i] = msh[j] + rot[i].h;
	}

	int max = -1;
	for (int i = 0; i < presents && used_all; i++)
		if (max < msh[i])
			max = msh[i];

	printf("%d\n", max);

	return 0;
}
