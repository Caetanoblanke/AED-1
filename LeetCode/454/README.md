Caetano Blanke M2 algoritmos e estrutura de dados I

LeetCode 454 - 4Sum II ( Soma de Quatro II )

	Dados quatro arrays de inteiros nums1, nums2, nums3 e nums4, todos de
	comprimento n, retorne o numero de tuplas ( i, j, k, l ) tais que:

		0 <= i, j, k, l < n
		nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

	Exemplo 1:

		Entrada: nums1 = [1,2], nums2 = [-2,-1],
				 nums3 = [-1,2], nums4 = [0,2]
		Saida: 2
		Explicacao: as duas tuplas sao:
		( 0, 0, 0, 1 ) --> 1 + ( -2 ) + ( -1 ) + 2 = 0
		( 1, 1, 0, 0 ) --> 2 + ( -1 ) + ( -1 ) + 0 = 0

	Exemplo 2:

		Entrada: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
		Saida: 1

	Restricoes:

		n == nums1.length == nums2.length == nums3.length == nums4.length
		1 <= n <= 200
		-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28