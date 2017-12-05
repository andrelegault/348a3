def HID_num(str)
    str = str.split
    str.each {|id|
        id.sub!(/\W/, "")
        idReg = id.match(/^[[:upper:]]{4}(\d{8})$/)
        if (idReg != nil)
            return idReg.captures[0]
        end
    }
    return nil
end