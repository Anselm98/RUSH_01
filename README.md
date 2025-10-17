# RUSH 01 - Number to Words Converter

## Description

Ce projet est un convertisseur de nombres en mots. Il prend un nombre entier non signé en argument et affiche sa représentation écrite en lettres.

## Compilation

```bash
make
```

Cela génère l'exécutable `rush-01`.

## Utilisation

```bash
./rush-01 <nombre>
```

### Exemples

```bash
./rush-01 42
# Output: forty two

./rush-01 0
# Output: zero

./rush-01 100000
# Output: one hundred thousand

./rush-01 10.4
# Output: error

./rush-01 -5
# Output: error
```

## Architecture du projet

### Fichiers

- **main.c** - Point d'entrée, validation des arguments
- **ipssi_atoi.c** - Conversion string → int (gestion des espaces et signes)
- **converter.c** - Logique principale de conversion avec tableaux de mots
- **utils.c** - Fonctions utilitaires (affichage, gestion dizaines/unités)
- **rush01.h** - Header avec prototypes
- **Makefile** - Compilation automatique

### Structure des données

Le programme utilise **3 tableaux globaux** pour stocker les mots :

```c
char *g_units[]  // "", "one", "two", ..., "nine"
char *g_teens[]  // "ten", "eleven", ..., "nineteen"
char *g_tens[]   // "", "", "twenty", "thirty", ..., "ninety"
```

Cette approche par tableaux évite l'utilisation d'un dictionnaire externe et rend le code plus simple.

## Fonctionnement

### 1. Validation (main.c)

- Vérifie qu'il y a exactement 1 argument
- Valide que l'argument est un entier non signé valide :
  - Pas de point décimal (10.4 → error)
  - Pas de signe négatif (-5 → error)
  - Uniquement des chiffres

### 2. Conversion string → int (ipssi_atoi.c)

- Supprime les espaces avant/après
- Gère les signes multiples (+/-)
- Convertit les caractères en nombre

### 3. Conversion nombre → mots (converter.c)

Utilise une **approche récursive** pour décomposer les nombres :

```
1234567890 → billion → million → thousand → hundred → tens → units
```

**Exemple avec 1,234,567** :
1. `1,234,567 >= 1,000,000` → Appel récursif pour `1` → "one million"
2. `234,567 >= 1,000` → Appel récursif pour `234` → "two hundred thirty four thousand"
3. `567 >= 100` → Appel récursif pour `5` → "five hundred"
4. `67 >= 20` → Lookup dans `g_tens[6]` → "sixty"
5. `7` → Lookup dans `g_units[7]` → "seven"

**Résultat** : "one million two hundred thirty four thousand five hundred sixty seven"

### 4. Gestion des cas spéciaux

- **0** → Retourne directement "zero"
- **10-19** → Utilise le tableau `g_teens[]` (mots irréguliers)
- **Multiples de 10** → Utilise `g_tens[]` sans ajouter d'unité
- **Grands nombres** → Récursion sur billion, million, thousand

### 5. Affichage (utils.c)

- `write_str()` : Affiche une chaîne avec `write()`
- `handle_tens_units()` : Gère l'affichage des dizaines (20-99) et unités (1-9)
- Gère les espaces entre les mots avec un flag `first`




### 6. Fichiers

- **converter.c** : Max 5 fonctions (norminette)
- **utils.c** : Fonctions helper pour respecter la limite
- **main.c** : Validation et point d'entrée
- **ipssi_atoi.c** : Fonction de conversion réutilisable