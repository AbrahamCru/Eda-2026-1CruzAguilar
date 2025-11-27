
memoria = {1: 0, 2: 1}

def fibonacci(n):
    """Cálculo recursivo de Fibonacci usando memorización"""
    if n in memoria:
        return memoria[n]

    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return memoria[n]



def main():
    posiciones = [7, 21, 40, 71, 94]

    print("\n--- RESULTADOS DE LA SUCESIÓN DE FIBONACCI ---\n")
    for pos in posiciones:
        print(f"Fibonacci({pos}) =", fibonacci(pos))

    print("\n--- FIN DEL PROGRAMA ---\n")


if __name__ == "__main__":
    main()
