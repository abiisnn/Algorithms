string defangIPaddr(string address) {
    string defanged = "";
    for(int i = 0; i < int(address.size()); i++) {
        if(address[i] == '.') {
            defanged += "[.]";
        } else {
            defanged += address[i];
        }
    }
    return defanged;
}