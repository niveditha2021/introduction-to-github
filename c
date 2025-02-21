import json

# Helper function to decode the base-encoded value
def decode_base(value, base):
    decoded_value = 0
    power = 0
    for digit in reversed(value):
        decoded_value += int(digit, base) * (base ** podata.jsonwer)
        power += 1
    return decoded_value

# Function to calculate the constant term of the polynomial using Lagrange Interpolation
def lagrange_interpolation_at_zero(roots):
    # Applying the Lagrange interpolation formula for evaluating polynomial at x = 0
    c = 0
    for i in range(len(roots)):
        xi, yi = roots[i]
        # Compute the Lagrange basis polynomial L_i(x) at x=0
        li_at_0 = 1
        for j in range(len(roots)):
            if i != j:
                xj, _ = roots[j]
                li_at_0 *= xj / (xi - xj)
        c += yi * li_at_0
    return int(c)

# Function to parse the input JSON and process it
def process_input(json_input):
    keys = json_input["keys"]
    n = keys["n"]
    k = keys["k"]
    
    # List to store decoded roots (x, y)
    roots = []
    
    # Parse each root
    for key in json_input:
        if key != "keys":  # Skip the "keys" part
            base = int(json_input[key]["base"])
            value = json_input[key]["value"]
            x = int(key)
            y = decode_base(value, base)
            roots.append((x, y))
    
    # Compute the constant term using Lagrange Interpolation at x = 0
    c = lagrange_interpolation_at_zero(roots)
    return c

# Example Test Case 1
test_case_1 = {
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}

# Example Test Case 2
test_case_2 = {
    "keys": {
        "n": 10,
        "k": 7
    },
    "1": {
        "base": "7",
        "value": "420020006424065463"
    },
    "2": {
        "base": "7",
        "value": "10511630252064643035"
    },
    "3": {
        "base": "2",
        "value": "101010101001100101011100000001000111010010111101100100010"
    },
    "4": {
        "base": "8",
        "value": "31261003022226126015"
    },
    "5": {
        "base": "7",
        "value": "2564201006101516132035"
    },
    "6": {
        "base": "15",
        "value": "a3c97ed550c69484"
    },
    "7": {
        "base": "13",
        "value": "134b08c8739552a734"
    },
    "8": {
        "base": "10",
        "value": "23600283241050447333"
    },
    "9": {
        "base": "9",
        "value": "375870320616068547135"
    },
    "10": {
        "base": "6",
        "value": "30140555423010311322515333"
    }
}

