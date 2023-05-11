.pragma library

const maxNumberChannel = 5

function getChannels() {
    let channels = []
    let template = "channel"
    for (var i = 0; i < maxNumberChannel; ++i) {
        let channel = template + i
        channels.push(channel)
    }

    return channels
}

function rangesVoltages() {
    let voltages = ["0.0000001 ... 0.001", "0.001 ... 1.0", "1.0 ... 1000.0", "1000.0 ... 1000000.0"]
    return voltages
}

function findVoltages(range) {
    let voltages = ["0.0000001 ... 0.001", "0.001 ... 1.0", "1.0 ... 1000.0", "1000.0 ... 1000000.0"]

    if (range === voltages[0])
        return "range0"
    else if (range === voltages[1])
        return "range1"
    else if (range === voltages[2])
        return "range2"
    else if (range === voltages[3])
        return "range3"
}
