function multiplyMatrices(matrixA, matrixB) {
  if (!Array.isArray(matrixA) || !Array.isArray(matrixB)) {
    throw new Error('Both inputs must be 2D arrays.');
  }

  const rowsA = matrixA.length;
  const colsA = rowsA > 0 ? matrixA[0].length : 0;
  const rowsB = matrixB.length;
  const colsB = rowsB > 0 ? matrixB[0].length : 0;

  if (rowsA === 0 || rowsB === 0 || colsA === 0 || colsB === 0) {
    return [];
  }

  for (let i = 0; i < rowsA; i++) {
    if (!Array.isArray(matrixA[i]) || matrixA[i].length !== colsA) {
      throw new Error('Matrix A must be a rectangular 2D array.');
    }
  }

  for (let i = 0; i < rowsB; i++) {
    if (!Array.isArray(matrixB[i]) || matrixB[i].length !== colsB) {
      throw new Error('Matrix B must be a rectangular 2D array.');
    }
  }

  if (colsA !== rowsB) {
    throw new Error('Matrix dimensions are not compatible for multiplication.');
  }

  const result = Array.from({ length: rowsA }, () => Array(colsB).fill(0));

  for (let i = 0; i < rowsA; i++) {
    for (let j = 0; j < colsB; j++) {
      let sum = 0;
      for (let k = 0; k < colsA; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      result[i][j] = sum;
    }
  }

  return result;
}

// Example usage:
const matrixA = [
  [1, 2, 3],
  [4, 5, 6]
];

const matrixB = [
  [7, 8],
  [9, 10],
  [11, 12]
];

console.log(multiplyMatrices(matrixA, matrixB));
