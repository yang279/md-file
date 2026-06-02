var exports = exports || {};
exports.ByteBuffer = exports.ByteBuffer || require("kiwi-schema").ByteBuffer;

exports["decodePaint"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["PaintType"][bb.readVarUint()];
        break;

      case 2:
        result["color"] = this["decodeColor"](bb);
        break;

      case 3:
        result["opacity"] = bb.readVarFloat();
        break;

      case 4:
        result["visible"] = !!bb.readByte();
        break;

      case 5:
        result["blendMode"] = this["BlendMode"][bb.readVarUint()];
        break;

      case 6:
        var length = bb.readVarUint();
        var values = result["stops"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeColorStop"](bb);
        break;

      case 7:
        result["transform"] = this["decodeMatrix"](bb);
        break;

      case 8:
        result["image"] = this["decodeImageMessage"](bb);
        break;

      case 9:
        result["imageThumbnail"] = this["decodeImageMessage"](bb);
        break;

      case 10:
        result["animatedImage"] = this["decodeImageMessage"](bb);
        break;

      case 11:
        result["animationFrame"] = bb.readVarInt();
        break;

      case 12:
        result["imageScaleMode"] = this["ImageScaleMode"][bb.readVarUint()];
        break;

      case 13:
        result["rotation"] = bb.readVarFloat();
        break;

      case 14:
        result["scale"] = bb.readVarFloat();
        break;

      case 15:
        result["paintFilter"] = this["decodePaintFilterMessage"](bb);
        break;

      case 16:
        var length = bb.readVarUint();
        var values = result["emojiCodePoints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
        break;

      case 17:
        result["originalImageWidth"] = bb.readVarInt();
        break;

      case 18:
        result["originalImageHeight"] = bb.readVarInt();
        break;

      case 19:
        result["video"] = this["decodeImageMessage"](bb);
        break;

      case 20:
        result["colorVar"] = this["decodeVariableData"](bb);
        break;

      case 21:
        var length = bb.readVarUint();
        var values = result["stopsVar"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeColorStopVar"](bb);
        break;

      case 22:
        result["patternSpacing"] = this["decodeVector"](bb);
        break;

      case 23:
        result["patternTileType"] = this["PatternTileType"][bb.readVarUint()];
        break;

      case 24:
        result["verticalAlignment"] = this["PatternAlignment"][bb.readVarUint()];
        break;

      case 25:
        result["horizontalAlignment"] = this["PatternAlignment"][bb.readVarUint()];
        break;

      case 26:
        result["sourceNodeId"] = this["decodeGUID"](bb);
        break;

      case 27:
        result["spacing"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePaint"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["PaintType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PaintType\""); bb.writeVarUint(encoded);
  }

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeColor"](value, bb);
  }

  var value = message["opacity"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["visible"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }

  var value = message["blendMode"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["BlendMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"BlendMode\""); bb.writeVarUint(encoded);
  }

  var value = message["stops"];
  if (value != null) {
    bb.writeVarUint(6);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeColorStop"](value, bb);
    }
  }

  var value = message["transform"];
  if (value != null) {
    bb.writeVarUint(7);
    this["encodeMatrix"](value, bb);
  }

  var value = message["image"];
  if (value != null) {
    bb.writeVarUint(8);
    this["encodeImageMessage"](value, bb);
  }

  var value = message["imageThumbnail"];
  if (value != null) {
    bb.writeVarUint(9);
    this["encodeImageMessage"](value, bb);
  }

  var value = message["animatedImage"];
  if (value != null) {
    bb.writeVarUint(10);
    this["encodeImageMessage"](value, bb);
  }

  var value = message["animationFrame"];
  if (value != null) {
    bb.writeVarUint(11);
    bb.writeVarInt(value);
  }

  var value = message["imageScaleMode"];
  if (value != null) {
    bb.writeVarUint(12);
    var encoded = this["ImageScaleMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ImageScaleMode\""); bb.writeVarUint(encoded);
  }

  var value = message["rotation"];
  if (value != null) {
    bb.writeVarUint(13);
    bb.writeVarFloat(value);
  }

  var value = message["scale"];
  if (value != null) {
    bb.writeVarUint(14);
    bb.writeVarFloat(value);
  }

  var value = message["paintFilter"];
  if (value != null) {
    bb.writeVarUint(15);
    this["encodePaintFilterMessage"](value, bb);
  }

  var value = message["emojiCodePoints"];
  if (value != null) {
    bb.writeVarUint(16);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  }

  var value = message["originalImageWidth"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeVarInt(value);
  }

  var value = message["originalImageHeight"];
  if (value != null) {
    bb.writeVarUint(18);
    bb.writeVarInt(value);
  }

  var value = message["video"];
  if (value != null) {
    bb.writeVarUint(19);
    this["encodeImageMessage"](value, bb);
  }

  var value = message["colorVar"];
  if (value != null) {
    bb.writeVarUint(20);
    this["encodeVariableData"](value, bb);
  }

  var value = message["stopsVar"];
  if (value != null) {
    bb.writeVarUint(21);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeColorStopVar"](value, bb);
    }
  }

  var value = message["patternSpacing"];
  if (value != null) {
    bb.writeVarUint(22);
    this["encodeVector"](value, bb);
  }

  var value = message["patternTileType"];
  if (value != null) {
    bb.writeVarUint(23);
    var encoded = this["PatternTileType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PatternTileType\""); bb.writeVarUint(encoded);
  }

  var value = message["verticalAlignment"];
  if (value != null) {
    bb.writeVarUint(24);
    var encoded = this["PatternAlignment"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PatternAlignment\""); bb.writeVarUint(encoded);
  }

  var value = message["horizontalAlignment"];
  if (value != null) {
    bb.writeVarUint(25);
    var encoded = this["PatternAlignment"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PatternAlignment\""); bb.writeVarUint(encoded);
  }

  var value = message["sourceNodeId"];
  if (value != null) {
    bb.writeVarUint(26);
    this["encodeGUID"](value, bb);
  }

  var value = message["spacing"];
  if (value != null) {
    bb.writeVarUint(27);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePaintFilterMessage"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["tint"] = bb.readVarFloat();
        break;

      case 2:
        result["shadows"] = bb.readVarFloat();
        break;

      case 3:
        result["highlights"] = bb.readVarFloat();
        break;

      case 4:
        result["exposure"] = bb.readVarFloat();
        break;

      case 5:
        result["temperature"] = bb.readVarFloat();
        break;

      case 6:
        result["vibrance"] = bb.readVarFloat();
        break;

      case 7:
        result["contrast"] = bb.readVarFloat();
        break;

      case 8:
        result["hue"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePaintFilterMessage"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["tint"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["shadows"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["highlights"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["exposure"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["temperature"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarFloat(value);
  }

  var value = message["vibrance"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarFloat(value);
  }

  var value = message["contrast"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarFloat(value);
  }

  var value = message["hue"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeColorStop"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["color"] = this["decodeColor"](bb);
        break;

      case 2:
        result["position"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeColorStop"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeColor"](value, bb);
  }

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeImageMessage"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["hash"] = bb.readByteArray();
        break;

      case 2:
        result["name"] = bb.readString();
        break;

      case 3:
        result["dataBlob"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeImageMessage"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["hash"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByteArray(value);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["dataBlob"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePath"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["blobIndex"] = bb.readVarInt();
        break;

      case 2:
        result["windingRule"] = this["WindingRule"][bb.readVarUint()];
        break;

      case 3:
        result["pxTag"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePath"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["blobIndex"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["windingRule"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["WindingRule"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"WindingRule\""); bb.writeVarUint(encoded);
  }

  var value = message["pxTag"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeGUIDPath"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["guids"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeGUIDPath"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guids"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVectorData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["vectorNetworkBlob"] = bb.readVarInt();
        break;

      case 2:
        result["normalizedSize"] = this["decodeVector"](bb);
        break;

      case 3:
        var length = bb.readVarUint();
        var values = result["styleOverrideTable"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVectorStyleData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVectorData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["vectorNetworkBlob"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["normalizedSize"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }

  var value = message["styleOverrideTable"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVectorStyleData"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeArcData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["startingAngle"] = bb.readVarFloat();
        break;

      case 2:
        result["endingAngle"] = bb.readVarFloat();
        break;

      case 3:
        result["innerRadius"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeArcData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["startingAngle"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["endingAngle"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["innerRadius"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeEffect"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["EffectType"][bb.readVarUint()];
        break;

      case 2:
        result["color"] = this["decodeColor"](bb);
        break;

      case 3:
        result["offset"] = this["decodeVector"](bb);
        break;

      case 4:
        result["radius"] = bb.readVarFloat();
        break;

      case 5:
        result["visible"] = !!bb.readByte();
        break;

      case 6:
        result["blendMode"] = this["BlendMode"][bb.readVarUint()];
        break;

      case 7:
        result["spread"] = bb.readVarFloat();
        break;

      case 8:
        result["showShadowBehindNode"] = !!bb.readByte();
        break;

      case 9:
        result["saturation"] = bb.readVarFloat();
        break;

      case 10:
        result["radiusVar"] = this["decodeVariableData"](bb);
        break;

      case 11:
        result["colorVar"] = this["decodeVariableData"](bb);
        break;

      case 12:
        result["spreadVar"] = this["decodeVariableData"](bb);
        break;

      case 13:
        result["xVar"] = this["decodeVariableData"](bb);
        break;

      case 14:
        result["yVar"] = this["decodeVariableData"](bb);
        break;

      case 15:
        result["refractionRadius"] = bb.readVarFloat();
        break;

      case 16:
        result["specularAngle"] = bb.readVarFloat();
        break;

      case 17:
        result["specularIntensity"] = bb.readVarFloat();
        break;

      case 18:
        result["chromaticAberration"] = bb.readVarFloat();
        break;

      case 19:
        result["refractionIntensity"] = bb.readVarFloat();
        break;

      case 20:
        result["brightness"] = bb.readVarFloat();
        break;

      case 21:
        result["uniformLight"] = !!bb.readByte();
        break;

      case 22:
        result["blurOpType"] = this["BlurOpType"][bb.readVarUint()];
        break;

      case 23:
        result["startRadius"] = bb.readVarFloat();
        break;

      case 24:
        result["transform"] = this["decodeMatrix"](bb);
        break;

      case 25:
        result["bevelSize"] = bb.readVarFloat();
        break;

      case 26:
        result["noiseSize"] = this["decodeVector"](bb);
        break;

      case 27:
        result["density"] = bb.readVarFloat();
        break;

      case 28:
        result["noiseType"] = this["NoiseType"][bb.readVarUint()];
        break;

      case 29:
        result["opacity"] = bb.readVarFloat();
        break;

      case 30:
        result["secondaryColor"] = this["decodeColor"](bb);
        break;

      case 31:
        result["clipToShape"] = !!bb.readByte();
        break;

      case 32:
        result["seed"] = bb.readVarInt();
        break;

      case 33:
        result["isImpact"] = !!bb.readByte();
        break;

      case 34:
        result["samplingRange"] = bb.readVarFloat();
        break;

      case 35:
        result["splay"] = bb.readVarFloat();
        break;

      case 36:
        result["isConvex"] = !!bb.readByte();
        break;

      case 37:
        result["center"] = this["decodeVector"](bb);
        break;

      case 38:
        result["motionAngle"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeEffect"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["EffectType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"EffectType\""); bb.writeVarUint(encoded);
  }

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeColor"](value, bb);
  }

  var value = message["offset"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeVector"](value, bb);
  }

  var value = message["radius"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["visible"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeByte(value);
  }

  var value = message["blendMode"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["BlendMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"BlendMode\""); bb.writeVarUint(encoded);
  }

  var value = message["spread"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarFloat(value);
  }

  var value = message["showShadowBehindNode"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeByte(value);
  }

  var value = message["saturation"];
  if (value != null) {
    bb.writeVarUint(9);
    bb.writeVarFloat(value);
  }

  var value = message["radiusVar"];
  if (value != null) {
    bb.writeVarUint(10);
    this["encodeVariableData"](value, bb);
  }

  var value = message["colorVar"];
  if (value != null) {
    bb.writeVarUint(11);
    this["encodeVariableData"](value, bb);
  }

  var value = message["spreadVar"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeVariableData"](value, bb);
  }

  var value = message["xVar"];
  if (value != null) {
    bb.writeVarUint(13);
    this["encodeVariableData"](value, bb);
  }

  var value = message["yVar"];
  if (value != null) {
    bb.writeVarUint(14);
    this["encodeVariableData"](value, bb);
  }

  var value = message["refractionRadius"];
  if (value != null) {
    bb.writeVarUint(15);
    bb.writeVarFloat(value);
  }

  var value = message["specularAngle"];
  if (value != null) {
    bb.writeVarUint(16);
    bb.writeVarFloat(value);
  }

  var value = message["specularIntensity"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeVarFloat(value);
  }

  var value = message["chromaticAberration"];
  if (value != null) {
    bb.writeVarUint(18);
    bb.writeVarFloat(value);
  }

  var value = message["refractionIntensity"];
  if (value != null) {
    bb.writeVarUint(19);
    bb.writeVarFloat(value);
  }

  var value = message["brightness"];
  if (value != null) {
    bb.writeVarUint(20);
    bb.writeVarFloat(value);
  }

  var value = message["uniformLight"];
  if (value != null) {
    bb.writeVarUint(21);
    bb.writeByte(value);
  }

  var value = message["blurOpType"];
  if (value != null) {
    bb.writeVarUint(22);
    var encoded = this["BlurOpType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"BlurOpType\""); bb.writeVarUint(encoded);
  }

  var value = message["startRadius"];
  if (value != null) {
    bb.writeVarUint(23);
    bb.writeVarFloat(value);
  }

  var value = message["transform"];
  if (value != null) {
    bb.writeVarUint(24);
    this["encodeMatrix"](value, bb);
  }

  var value = message["bevelSize"];
  if (value != null) {
    bb.writeVarUint(25);
    bb.writeVarFloat(value);
  }

  var value = message["noiseSize"];
  if (value != null) {
    bb.writeVarUint(26);
    this["encodeVector"](value, bb);
  }

  var value = message["density"];
  if (value != null) {
    bb.writeVarUint(27);
    bb.writeVarFloat(value);
  }

  var value = message["noiseType"];
  if (value != null) {
    bb.writeVarUint(28);
    var encoded = this["NoiseType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NoiseType\""); bb.writeVarUint(encoded);
  }

  var value = message["opacity"];
  if (value != null) {
    bb.writeVarUint(29);
    bb.writeVarFloat(value);
  }

  var value = message["secondaryColor"];
  if (value != null) {
    bb.writeVarUint(30);
    this["encodeColor"](value, bb);
  }

  var value = message["clipToShape"];
  if (value != null) {
    bb.writeVarUint(31);
    bb.writeByte(value);
  }

  var value = message["seed"];
  if (value != null) {
    bb.writeVarUint(32);
    bb.writeVarInt(value);
  }

  var value = message["isImpact"];
  if (value != null) {
    bb.writeVarUint(33);
    bb.writeByte(value);
  }

  var value = message["samplingRange"];
  if (value != null) {
    bb.writeVarUint(34);
    bb.writeVarFloat(value);
  }

  var value = message["splay"];
  if (value != null) {
    bb.writeVarUint(35);
    bb.writeVarFloat(value);
  }

  var value = message["isConvex"];
  if (value != null) {
    bb.writeVarUint(36);
    bb.writeByte(value);
  }

  var value = message["center"];
  if (value != null) {
    bb.writeVarUint(37);
    this["encodeVector"](value, bb);
  }

  var value = message["motionAngle"];
  if (value != null) {
    bb.writeVarUint(38);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSymbolData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["symbolID"] = this["decodeGUID"](bb);
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["symbolOverrides"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePixsoNode"](bb);
        break;

      case 3:
        result["uniformScaleFactor"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSymbolData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["symbolID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["symbolOverrides"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePixsoNode"](value, bb);
    }
  }

  var value = message["uniformScaleFactor"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeLayoutGrid"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["LayoutGridType"][bb.readVarUint()];
        break;

      case 2:
        result["axis"] = this["Axis"][bb.readVarUint()];
        break;

      case 3:
        result["visible"] = !!bb.readByte();
        break;

      case 4:
        result["numSections"] = bb.readVarInt();
        break;

      case 5:
        result["offset"] = bb.readVarFloat();
        break;

      case 6:
        result["sectionSize"] = bb.readVarFloat();
        break;

      case 7:
        result["gutterSize"] = bb.readVarFloat();
        break;

      case 8:
        result["color"] = this["decodeColor"](bb);
        break;

      case 9:
        result["pattern"] = this["LayoutGridPattern"][bb.readVarUint()];
        break;

      case 10:
        result["numSectionsVar"] = this["decodeVariableData"](bb);
        break;

      case 11:
        result["offsetVar"] = this["decodeVariableData"](bb);
        break;

      case 12:
        result["sectionSizeVar"] = this["decodeVariableData"](bb);
        break;

      case 13:
        result["gutterSizeVar"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeLayoutGrid"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["LayoutGridType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"LayoutGridType\""); bb.writeVarUint(encoded);
  }

  var value = message["axis"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["Axis"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Axis\""); bb.writeVarUint(encoded);
  }

  var value = message["visible"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByte(value);
  }

  var value = message["numSections"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }

  var value = message["offset"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarFloat(value);
  }

  var value = message["sectionSize"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarFloat(value);
  }

  var value = message["gutterSize"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarFloat(value);
  }

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(8);
    this["encodeColor"](value, bb);
  }

  var value = message["pattern"];
  if (value != null) {
    bb.writeVarUint(9);
    var encoded = this["LayoutGridPattern"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"LayoutGridPattern\""); bb.writeVarUint(encoded);
  }

  var value = message["numSectionsVar"];
  if (value != null) {
    bb.writeVarUint(10);
    this["encodeVariableData"](value, bb);
  }

  var value = message["offsetVar"];
  if (value != null) {
    bb.writeVarUint(11);
    this["encodeVariableData"](value, bb);
  }

  var value = message["sectionSizeVar"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeVariableData"](value, bb);
  }

  var value = message["gutterSizeVar"];
  if (value != null) {
    bb.writeVarUint(13);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeGridTrackSizing"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["type"] = this["GridTrackSizingType"][bb.readVarUint()];
        break;

      case 3:
        result["value"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeGridTrackSizing"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["GridTrackSizingType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"GridTrackSizingType\""); bb.writeVarUint(encoded);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeExportConstraint"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["ExportConstraintType"][bb.readVarUint()];
        break;

      case 2:
        result["value"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeExportConstraint"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ExportConstraintType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ExportConstraintType\""); bb.writeVarUint(encoded);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeExportSettings"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["suffix"] = bb.readString();
        break;

      case 2:
        result["imageType"] = this["ImageType"][bb.readVarUint()];
        break;

      case 3:
        result["constraint"] = this["decodeExportConstraint"](bb);
        break;

      case 4:
        result["svgDataName"] = !!bb.readByte();
        break;

      case 5:
        result["svgIDMode"] = this["ExportSVGIDMode"][bb.readVarUint()];
        break;

      case 6:
        result["svgOutlineText"] = !!bb.readByte();
        break;

      case 7:
        result["contentsOnly"] = !!bb.readByte();
        break;

      case 8:
        result["svgForceStrokeMasks"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeExportSettings"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["suffix"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["imageType"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["ImageType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ImageType\""); bb.writeVarUint(encoded);
  }

  var value = message["constraint"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeExportConstraint"](value, bb);
  }

  var value = message["svgDataName"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }

  var value = message["svgIDMode"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["ExportSVGIDMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ExportSVGIDMode\""); bb.writeVarUint(encoded);
  }

  var value = message["svgOutlineText"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeByte(value);
  }

  var value = message["contentsOnly"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeByte(value);
  }

  var value = message["svgForceStrokeMasks"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeFontName"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["family"] = bb.readString();
        break;

      case 2:
        result["style"] = bb.readString();
        break;

      case 3:
        result["postscript"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeFontName"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["family"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["style"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["postscript"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTextData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["characters"] = bb.readString();
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["characterStyleIDs"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
        break;

      case 3:
        var length = bb.readVarUint();
        var values = result["styleOverrideTable"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeTextStyleData"](bb);
        break;

      case 4:
        result["layoutSize"] = this["decodeVector"](bb);
        break;

      case 5:
        var length = bb.readVarUint();
        var values = result["baselines"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeBaseline"](bb);
        break;

      case 6:
        var length = bb.readVarUint();
        var values = result["glyphs"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGlyph"](bb);
        break;

      case 7:
        var length = bb.readVarUint();
        var values = result["decorations"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDecoration"](bb);
        break;

      case 8:
        result["layoutVersion"] = bb.readVarInt();
        break;

      case 9:
        var length = bb.readVarUint();
        var values = result["fontMetaData"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeFontMetaData"](bb);
        break;

      case 10:
        var length = bb.readVarUint();
        var values = result["fallbackFonts"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeFontName"](bb);
        break;

      case 11:
        var length = bb.readVarUint();
        var values = result["hyperlinkBoxes"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeHyperlinkBox"](bb);
        break;

      case 12:
        var length = bb.readVarUint();
        var values = result["paragraphStyle"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeParagraphStyle"](bb);
        break;

      case 13:
        var length = bb.readVarUint();
        var values = result["placeHolders"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePlaceHolder"](bb);
        break;

      case 14:
        result["truncationStartIndex"] = bb.readVarInt();
        break;

      case 15:
        result["truncatedHeight"] = bb.readVarFloat();
        break;

      case 16:
        var length = bb.readVarUint();
        var values = result["glyphPoses"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGlyphPose"](bb);
        break;

      case 17:
        result["isDirty"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTextData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["characters"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["characterStyleIDs"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  }

  var value = message["styleOverrideTable"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeTextStyleData"](value, bb);
    }
  }

  var value = message["layoutSize"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeVector"](value, bb);
  }

  var value = message["baselines"];
  if (value != null) {
    bb.writeVarUint(5);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeBaseline"](value, bb);
    }
  }

  var value = message["glyphs"];
  if (value != null) {
    bb.writeVarUint(6);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGlyph"](value, bb);
    }
  }

  var value = message["decorations"];
  if (value != null) {
    bb.writeVarUint(7);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDecoration"](value, bb);
    }
  }

  var value = message["layoutVersion"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeVarInt(value);
  }

  var value = message["fontMetaData"];
  if (value != null) {
    bb.writeVarUint(9);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeFontMetaData"](value, bb);
    }
  }

  var value = message["fallbackFonts"];
  if (value != null) {
    bb.writeVarUint(10);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeFontName"](value, bb);
    }
  }

  var value = message["hyperlinkBoxes"];
  if (value != null) {
    bb.writeVarUint(11);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeHyperlinkBox"](value, bb);
    }
  }

  var value = message["paragraphStyle"];
  if (value != null) {
    bb.writeVarUint(12);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeParagraphStyle"](value, bb);
    }
  }

  var value = message["placeHolders"];
  if (value != null) {
    bb.writeVarUint(13);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePlaceHolder"](value, bb);
    }
  }

  var value = message["truncationStartIndex"];
  if (value != null) {
    bb.writeVarUint(14);
    bb.writeVarInt(value);
  }

  var value = message["truncatedHeight"];
  if (value != null) {
    bb.writeVarUint(15);
    bb.writeVarFloat(value);
  }

  var value = message["glyphPoses"];
  if (value != null) {
    bb.writeVarUint(16);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGlyphPose"](value, bb);
    }
  }

  var value = message["isDirty"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeHyperlinkBox"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["bounds"] = this["decodeRect"](bb);
        break;

      case 2:
        result["url"] = bb.readString();
        break;

      case 3:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["hyperlinkID"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeHyperlinkBox"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["bounds"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeRect"](value, bb);
  }

  var value = message["url"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["hyperlinkID"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeFontMetaData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["key"] = this["decodeFontName"](bb);
        break;

      case 2:
        result["fontLineHeight"] = bb.readVarFloat();
        break;

      case 3:
        result["fontDigest"] = bb.readByteArray();
        break;

      case 4:
        result["fontStyle"] = this["FontStyle"][bb.readVarUint()];
        break;

      case 5:
        result["fontWeight"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeFontMetaData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeFontName"](value, bb);
  }

  var value = message["fontLineHeight"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["fontDigest"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByteArray(value);
  }

  var value = message["fontStyle"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["FontStyle"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontStyle\""); bb.writeVarUint(encoded);
  }

  var value = message["fontWeight"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeDecoration"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["rects"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeRect"](bb);
        break;

      case 2:
        result["styleID"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeDecoration"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["rects"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeRect"](value, bb);
    }
  }

  var value = message["styleID"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeGlyph"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["blobIndex"] = bb.readVarInt();
        break;

      case 2:
        result["position"] = this["decodeVector"](bb);
        break;

      case 3:
        result["styleID"] = bb.readVarInt();
        break;

      case 4:
        result["fontSize"] = bb.readVarFloat();
        break;

      case 5:
        result["firstCharacter"] = bb.readVarInt();
        break;

      case 6:
        result["advance"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeGlyph"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["blobIndex"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }

  var value = message["styleID"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }

  var value = message["fontSize"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["firstCharacter"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarInt(value);
  }

  var value = message["advance"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeParagraphStyle"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["listType"] = this["TextListStyle"][bb.readVarUint()];
        break;

      case 2:
        result["indentationLevel"] = bb.readVarUint();
        break;

      case 3:
        result["listStartOffset"] = bb.readVarUint();
        break;

      case 4:
        result["isFirstLineOfList"] = !!bb.readByte();
        break;

      case 5:
        result["sourceDirectionality"] = this["Directionality"][bb.readVarUint()];
        break;

      case 6:
        result["directionality"] = this["Directionality"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeParagraphStyle"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["listType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["TextListStyle"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextListStyle\""); bb.writeVarUint(encoded);
  }

  var value = message["indentationLevel"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarUint(value);
  }

  var value = message["listStartOffset"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarUint(value);
  }

  var value = message["isFirstLineOfList"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }

  var value = message["sourceDirectionality"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["Directionality"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Directionality\""); bb.writeVarUint(encoded);
  }

  var value = message["directionality"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["Directionality"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Directionality\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeBaseline"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["position"] = this["decodeVector"](bb);
        break;

      case 2:
        result["width"] = bb.readVarFloat();
        break;

      case 3:
        result["lineY"] = bb.readVarFloat();
        break;

      case 4:
        result["lineHeight"] = bb.readVarFloat();
        break;

      case 5:
        result["lineAscent"] = bb.readVarFloat();
        break;

      case 6:
        result["firstCharacter"] = bb.readVarInt();
        break;

      case 7:
        result["endCharacter"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeBaseline"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeVector"](value, bb);
  }

  var value = message["width"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["lineY"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["lineHeight"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["lineAscent"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarFloat(value);
  }

  var value = message["firstCharacter"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarInt(value);
  }

  var value = message["endCharacter"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeKeyTrigger"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["keyCodes"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
        break;

      case 2:
        result["triggerDevice"] = this["TriggerDevice"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeKeyTrigger"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["keyCodes"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  }

  var value = message["triggerDevice"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["TriggerDevice"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TriggerDevice\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeDevice"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["PrototypeDeviceType"][bb.readVarUint()];
        break;

      case 2:
        result["size"] = this["decodeVector"](bb);
        break;

      case 3:
        result["presetIdentifier"] = bb.readString();
        break;

      case 4:
        result["rotation"] = this["DeviceRotation"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeDevice"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["PrototypeDeviceType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PrototypeDeviceType\""); bb.writeVarUint(encoded);
  }

  var value = message["size"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }

  var value = message["presetIdentifier"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["rotation"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["DeviceRotation"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"DeviceRotation\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeInteraction"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["event"] = this["decodePrototypeEvent"](bb);
        break;

      case 3:
        var length = bb.readVarUint();
        var values = result["actions"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePrototypeAction"](bb);
        break;

      case 4:
        result["isDeleted"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeInteraction"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["event"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodePrototypeEvent"](value, bb);
  }

  var value = message["actions"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePrototypeAction"](value, bb);
    }
  }

  var value = message["isDeleted"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeConditionalActions"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["actions"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePrototypeAction"](bb);
        break;

      case 2:
        result["condition"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeConditionalActions"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["actions"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePrototypeAction"](value, bb);
    }
  }

  var value = message["condition"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVideoPlayback"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["autoplay"] = !!bb.readByte();
        break;

      case 2:
        result["mediaLoop"] = !!bb.readByte();
        break;

      case 3:
        result["muted"] = !!bb.readByte();
        break;

      case 4:
        result["showControls"] = !!bb.readByte();
        break;

      case 5:
        result["startTimeMs"] = bb.readVarInt();
        break;

      case 6:
        result["endTimeMs"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVideoPlayback"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["autoplay"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByte(value);
  }

  var value = message["mediaLoop"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["muted"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByte(value);
  }

  var value = message["showControls"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }

  var value = message["startTimeMs"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarInt(value);
  }

  var value = message["endTimeMs"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableWidthPoint"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["position"] = bb.readVarFloat();
        break;

      case 2:
        result["ascent"] = bb.readVarFloat();
        break;

      case 3:
        result["descent"] = bb.readVarFloat();
        break;

      case 4:
        result["segmentId"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableWidthPoint"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["ascent"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["descent"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["segmentId"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeSelectedState"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["nodeID"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["stateType"] = this["PrototypeSelectedStateType"][bb.readVarUint()];
        break;

      case 3:
        result["selectGUID"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["stateAction"] = this["PrototypeStateAction"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeSelectedState"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["nodeID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["stateType"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["PrototypeSelectedStateType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PrototypeSelectedStateType\""); bb.writeVarUint(encoded);
  }

  var value = message["selectGUID"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["stateAction"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["PrototypeStateAction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PrototypeStateAction\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeStateChange"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["targetStateAction"] = this["PrototypeStateAction"][bb.readVarUint()];
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["selectedStates"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePrototypeSelectedState"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeStateChange"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["targetStateAction"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["PrototypeStateAction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PrototypeStateAction\""); bb.writeVarUint(encoded);
  }

  var value = message["selectedStates"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePrototypeSelectedState"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeAction"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["transitionNodeID"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["transitionType"] = this["TransitionType"][bb.readVarUint()];
        break;

      case 3:
        result["transitionDuration"] = bb.readVarFloat();
        break;

      case 4:
        result["easingType"] = this["EasingType"][bb.readVarUint()];
        break;

      case 5:
        result["transitionShouldSmartAnimate"] = !!bb.readByte();
        break;

      case 6:
        result["connectionType"] = this["ConnectionType"][bb.readVarUint()];
        break;

      case 7:
        result["connectionURL"] = bb.readString();
        break;

      case 8:
        result["overlayRelativePosition"] = this["decodeVector"](bb);
        break;

      case 9:
        result["navigationType"] = this["NavigationType"][bb.readVarUint()];
        break;

      case 10:
        result["transitionPreserveScroll"] = !!bb.readByte();
        break;

      case 11:
        var length = bb.readVarUint();
        var values = result["easingFunction"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        break;

      case 12:
        result["overflowType"] = this["OverflowType"][bb.readVarUint()];
        break;

      case 13:
        result["extraScrollOffset"] = this["decodeVector"](bb);
        break;

      case 14:
        result["showHide"] = this["PrototypeShowHide"][bb.readVarUint()];
        break;

      case 15:
        result["adjustSize"] = this["decodeProdAdjustSize"](bb);
        break;

      case 16:
        result["moving"] = this["decodeProdMoving"](bb);
        break;

      case 17:
        result["dynamicPanelStateStr"] = bb.readString();
        break;

      case 18:
        result["rotation"] = this["decodeProdRotate"](bb);
        break;

      case 19:
        result["waitingTime"] = bb.readVarFloat();
        break;

      case 20:
        result["isLooping"] = !!bb.readByte();
        break;

      case 21:
        result["loopingDuration"] = bb.readVarFloat();
        break;

      case 22:
        result["targetVariable"] = this["decodePrototypeVariableTarget"](bb);
        break;

      case 23:
        result["targetVariableData"] = this["decodeVariableData"](bb);
        break;

      case 24:
        result["targetVariableSetID"] = this["decodeAssetID"](bb);
        break;

      case 25:
        result["targetVariableModeID"] = this["decodeGUID"](bb);
        break;

      case 26:
        var length = bb.readVarUint();
        var values = result["conditionalActions"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeConditionalActions"](bb);
        break;

      case 27:
        result["transitionResetVideoPosition"] = !!bb.readByte();
        break;

      case 28:
        result["transitionResetScrollPosition"] = !!bb.readByte();
        break;

      case 29:
        result["transitionResetInteractiveComponents"] = !!bb.readByte();
        break;

      case 30:
        result["DisplayTopLevel"] = !!bb.readByte();
        break;

      case 31:
        result["mediaSkipToTime"] = bb.readVarFloat();
        break;

      case 32:
        result["mediaSkipByAmount"] = bb.readVarFloat();
        break;

      case 33:
        result["mediaAction"] = this["MediaAction"][bb.readVarUint()];
        break;

      case 34:
        result["stateChange"] = this["decodePrototypeStateChange"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeAction"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["transitionNodeID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["transitionType"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["TransitionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TransitionType\""); bb.writeVarUint(encoded);
  }

  var value = message["transitionDuration"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["easingType"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["EasingType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"EasingType\""); bb.writeVarUint(encoded);
  }

  var value = message["transitionShouldSmartAnimate"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeByte(value);
  }

  var value = message["connectionType"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["ConnectionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConnectionType\""); bb.writeVarUint(encoded);
  }

  var value = message["connectionURL"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeString(value);
  }

  var value = message["overlayRelativePosition"];
  if (value != null) {
    bb.writeVarUint(8);
    this["encodeVector"](value, bb);
  }

  var value = message["navigationType"];
  if (value != null) {
    bb.writeVarUint(9);
    var encoded = this["NavigationType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NavigationType\""); bb.writeVarUint(encoded);
  }

  var value = message["transitionPreserveScroll"];
  if (value != null) {
    bb.writeVarUint(10);
    bb.writeByte(value);
  }

  var value = message["easingFunction"];
  if (value != null) {
    bb.writeVarUint(11);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }

  var value = message["overflowType"];
  if (value != null) {
    bb.writeVarUint(12);
    var encoded = this["OverflowType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OverflowType\""); bb.writeVarUint(encoded);
  }

  var value = message["extraScrollOffset"];
  if (value != null) {
    bb.writeVarUint(13);
    this["encodeVector"](value, bb);
  }

  var value = message["showHide"];
  if (value != null) {
    bb.writeVarUint(14);
    var encoded = this["PrototypeShowHide"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PrototypeShowHide\""); bb.writeVarUint(encoded);
  }

  var value = message["adjustSize"];
  if (value != null) {
    bb.writeVarUint(15);
    this["encodeProdAdjustSize"](value, bb);
  }

  var value = message["moving"];
  if (value != null) {
    bb.writeVarUint(16);
    this["encodeProdMoving"](value, bb);
  }

  var value = message["dynamicPanelStateStr"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeString(value);
  }

  var value = message["rotation"];
  if (value != null) {
    bb.writeVarUint(18);
    this["encodeProdRotate"](value, bb);
  }

  var value = message["waitingTime"];
  if (value != null) {
    bb.writeVarUint(19);
    bb.writeVarFloat(value);
  }

  var value = message["isLooping"];
  if (value != null) {
    bb.writeVarUint(20);
    bb.writeByte(value);
  }

  var value = message["loopingDuration"];
  if (value != null) {
    bb.writeVarUint(21);
    bb.writeVarFloat(value);
  }

  var value = message["targetVariable"];
  if (value != null) {
    bb.writeVarUint(22);
    this["encodePrototypeVariableTarget"](value, bb);
  }

  var value = message["targetVariableData"];
  if (value != null) {
    bb.writeVarUint(23);
    this["encodeVariableData"](value, bb);
  }

  var value = message["targetVariableSetID"];
  if (value != null) {
    bb.writeVarUint(24);
    this["encodeAssetID"](value, bb);
  }

  var value = message["targetVariableModeID"];
  if (value != null) {
    bb.writeVarUint(25);
    this["encodeGUID"](value, bb);
  }

  var value = message["conditionalActions"];
  if (value != null) {
    bb.writeVarUint(26);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeConditionalActions"](value, bb);
    }
  }

  var value = message["transitionResetVideoPosition"];
  if (value != null) {
    bb.writeVarUint(27);
    bb.writeByte(value);
  }

  var value = message["transitionResetScrollPosition"];
  if (value != null) {
    bb.writeVarUint(28);
    bb.writeByte(value);
  }

  var value = message["transitionResetInteractiveComponents"];
  if (value != null) {
    bb.writeVarUint(29);
    bb.writeByte(value);
  }

  var value = message["DisplayTopLevel"];
  if (value != null) {
    bb.writeVarUint(30);
    bb.writeByte(value);
  }

  var value = message["mediaSkipToTime"];
  if (value != null) {
    bb.writeVarUint(31);
    bb.writeVarFloat(value);
  }

  var value = message["mediaSkipByAmount"];
  if (value != null) {
    bb.writeVarUint(32);
    bb.writeVarFloat(value);
  }

  var value = message["mediaAction"];
  if (value != null) {
    bb.writeVarUint(33);
    var encoded = this["MediaAction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"MediaAction\""); bb.writeVarUint(encoded);
  }

  var value = message["stateChange"];
  if (value != null) {
    bb.writeVarUint(34);
    this["encodePrototypeStateChange"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeEvent"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["interactionType"] = this["InteractionType"][bb.readVarUint()];
        break;

      case 2:
        result["interactionMaintained"] = !!bb.readByte();
        break;

      case 3:
        result["interactionDuration"] = bb.readVarFloat();
        break;

      case 4:
        result["keyTrigger"] = this["decodeKeyTrigger"](bb);
        break;

      case 5:
        result["voiceEventPhrase"] = bb.readString();
        break;

      case 6:
        result["transitionTimeout"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeEvent"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["interactionType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["InteractionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"InteractionType\""); bb.writeVarUint(encoded);
  }

  var value = message["interactionMaintained"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["interactionDuration"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["keyTrigger"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeKeyTrigger"](value, bb);
  }

  var value = message["voiceEventPhrase"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeString(value);
  }

  var value = message["transitionTimeout"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeComponentPropDef"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["name"] = bb.readString();
        break;

      case 3:
        result["initialValue"] = this["decodeComponentPropValue"](bb);
        break;

      case 4:
        result["sortPosition"] = bb.readString();
        break;

      case 5:
        result["parentPropDefId"] = this["decodeGUID"](bb);
        break;

      case 6:
        result["type"] = this["ComponentPropType"][bb.readVarUint()];
        break;

      case 7:
        result["preferredValues"] = this["decodeComponentPropPreferredValues"](bb);
        break;

      case 8:
        result["isDeleted"] = !!bb.readByte();
        break;

      case 9:
        result["varValue"] = this["decodeVariableData"](bb);
        break;

      case 10:
        result["aliasName"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeComponentPropDef"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["initialValue"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeComponentPropValue"](value, bb);
  }

  var value = message["sortPosition"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeString(value);
  }

  var value = message["parentPropDefId"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeGUID"](value, bb);
  }

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["ComponentPropType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ComponentPropType\""); bb.writeVarUint(encoded);
  }

  var value = message["preferredValues"];
  if (value != null) {
    bb.writeVarUint(7);
    this["encodeComponentPropPreferredValues"](value, bb);
  }

  var value = message["isDeleted"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeByte(value);
  }

  var value = message["varValue"];
  if (value != null) {
    bb.writeVarUint(9);
    this["encodeVariableData"](value, bb);
  }

  var value = message["aliasName"];
  if (value != null) {
    bb.writeVarUint(10);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeComponentPropRef"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["defID"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["zombieFallbackName"] = bb.readString();
        break;

      case 3:
        result["componentPropNodeField"] = this["ComponentPropNodeField"][bb.readVarUint()];
        break;

      case 4:
        result["nodeField"] = bb.readVarUint();
        break;

      case 5:
        result["isDeleted"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeComponentPropRef"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["defID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["zombieFallbackName"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["componentPropNodeField"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["ComponentPropNodeField"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ComponentPropNodeField\""); bb.writeVarUint(encoded);
  }

  var value = message["nodeField"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarUint(value);
  }

  var value = message["isDeleted"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeComponentPropValue"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["textValue"] = this["decodeTextData"](bb);
        break;

      case 2:
        result["guidValue"] = this["decodeGUID"](bb);
        break;

      case 3:
        result["boolValue"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeComponentPropValue"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["textValue"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeTextData"](value, bb);
  }

  var value = message["guidValue"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }

  var value = message["boolValue"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeInstanceSwapPreferredValue"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["InstanceSwapPreferredValueType"][bb.readVarUint()];
        break;

      case 2:
        result["key"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeInstanceSwapPreferredValue"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["InstanceSwapPreferredValueType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"InstanceSwapPreferredValueType\""); bb.writeVarUint(encoded);
  }

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeComponentPropPreferredValues"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["stringValues"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readString();
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["instanceSwapValues"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeInstanceSwapPreferredValue"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeComponentPropPreferredValues"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["stringValues"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  }

  var value = message["instanceSwapValues"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeInstanceSwapPreferredValue"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeComponentPropAssignment"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["defID"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["value"] = this["decodeComponentPropValue"](bb);
        break;

      case 3:
        result["varValue"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeComponentPropAssignment"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["defID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeComponentPropValue"](value, bb);
  }

  var value = message["varValue"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeBlob"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["bytes"] = bb.readByteArray();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeBlob"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["bytes"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByteArray(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePixsoNode"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["guidPath"] = this["decodeGUIDPath"](bb);
        break;

      case 3:
        result["parentIndex"] = this["decodeParentIndex"](bb);
        break;

      case 4:
        result["phase"] = this["NodePhase"][bb.readVarUint()];
        break;

      case 5:
        result["transform"] = this["decodeMatrix"](bb);
        break;

      case 6:
        result["type"] = this["NodeType"][bb.readVarUint()];
        break;

      case 7:
        result["name"] = bb.readString();
        break;

      case 8:
        result["vectorData"] = this["decodeVectorData"](bb);
        break;

      case 9:
        result["version"] = bb.readString();
        break;

      case 10:
        result["visible"] = !!bb.readByte();
        break;

      case 11:
        result["count"] = bb.readVarInt();
        break;

      case 12:
        result["size"] = this["decodeVector"](bb);
        break;

      case 13:
        result["booleanOperation"] = this["BooleanOperation"][bb.readVarUint()];
        break;

      case 14:
        result["arcData"] = this["decodeArcData"](bb);
        break;

      case 15:
        result["blendMode"] = this["BlendMode"][bb.readVarUint()];
        break;

      case 16:
        result["cornerRadius"] = bb.readVarFloat();
        break;

      case 17:
        result["cornerSmoothing"] = bb.readVarFloat();
        break;

      case 18:
        result["opacity"] = bb.readVarFloat();
        break;

      case 19:
        result["locked"] = !!bb.readByte();
        break;

      case 20:
        var length = bb.readVarUint();
        var values = result["effects"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeEffect"](bb);
        break;

      case 21:
        var length = bb.readVarUint();
        var values = result["fillGeometry"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePath"](bb);
        break;

      case 22:
        var length = bb.readVarUint();
        var values = result["fillPaints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePaint"](bb);
        break;

      case 23:
        var length = bb.readVarUint();
        var values = result["dashPattern"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        break;

      case 24:
        result["stackCounterAlign"] = this["StackCounterAlign"][bb.readVarUint()];
        break;

      case 25:
        result["stackCounterSizing"] = this["StackSize"][bb.readVarUint()];
        break;

      case 26:
        result["stackHeight"] = this["StackSize"][bb.readVarUint()];
        break;

      case 27:
        result["stackHorizontalPadding"] = bb.readVarFloat();
        break;

      case 28:
        result["stackJustify"] = this["StackJustify"][bb.readVarUint()];
        break;

      case 29:
        result["stackMode"] = this["StackMode"][bb.readVarUint()];
        break;

      case 30:
        result["stackPadding"] = bb.readVarFloat();
        break;

      case 31:
        result["stackSpacing"] = bb.readVarFloat();
        break;

      case 32:
        result["stackVerticalPadding"] = bb.readVarFloat();
        break;

      case 33:
        result["stackWidth"] = this["StackSize"][bb.readVarUint()];
        break;

      case 34:
        result["strokeAlign"] = this["StrokeAlign"][bb.readVarUint()];
        break;

      case 35:
        result["strokeCap"] = this["StrokeCap"][bb.readVarUint()];
        break;

      case 36:
        var length = bb.readVarUint();
        var values = result["strokeGeometry"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePath"](bb);
        break;

      case 37:
        result["strokeJoin"] = this["StrokeJoin"][bb.readVarUint()];
        break;

      case 38:
        var length = bb.readVarUint();
        var values = result["strokePaints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePaint"](bb);
        break;

      case 39:
        result["strokeWeight"] = bb.readVarFloat();
        break;

      case 40:
        result["styleDescription"] = bb.readString();
        break;

      case 41:
        result["styleID"] = bb.readVarInt();
        break;

      case 42:
        result["styleType"] = this["StyleType"][bb.readVarUint()];
        break;

      case 43:
        result["symbolData"] = this["decodeSymbolData"](bb);
        break;

      case 44:
        result["symbolDescription"] = bb.readString();
        break;

      case 45:
        var length = bb.readVarUint();
        var values = result["layoutGrids"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeLayoutGrid"](bb);
        break;

      case 46:
        result["mask"] = !!bb.readByte();
        break;

      case 47:
        result["maskIsOutline"] = !!bb.readByte();
        break;

      case 48:
        result["starInnerScale"] = bb.readVarFloat();
        break;

      case 49:
        result["miterLimit"] = bb.readVarFloat();
        break;

      case 50:
        result["backgroundColor"] = this["decodeColor"](bb);
        break;

      case 51:
        result["backgroundEnabled"] = !!bb.readByte();
        break;

      case 52:
        result["backgroundOpacity"] = bb.readVarFloat();
        break;

      case 53:
        var length = bb.readVarUint();
        var values = result["backgroundPaints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePaint"](bb);
        break;

      case 54:
        result["exportBackgroundDisabled"] = !!bb.readByte();
        break;

      case 55:
        result["exportContentsOnly"] = !!bb.readByte();
        break;

      case 56:
        var length = bb.readVarUint();
        var values = result["exportSettings"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeExportSettings"](bb);
        break;

      case 57:
        result["exportTextAsSVGText"] = !!bb.readByte();
        break;

      case 58:
        result["fontName"] = this["decodeFontName"](bb);
        break;

      case 59:
        result["fontSize"] = bb.readVarFloat();
        break;

      case 60:
        result["fontVersion"] = bb.readString();
        break;

      case 61:
        result["paragraphIndent"] = bb.readVarFloat();
        break;

      case 62:
        result["paragraphSpacing"] = bb.readVarFloat();
        break;

      case 63:
        result["textAlignHorizontal"] = this["TextAlignHorizontal"][bb.readVarUint()];
        break;

      case 64:
        result["textAlignVertical"] = this["TextAlignVertical"][bb.readVarUint()];
        break;

      case 65:
        result["textAutoResize"] = this["TextAutoResize"][bb.readVarUint()];
        break;

      case 66:
        result["textCase"] = this["TextCase"][bb.readVarUint()];
        break;

      case 67:
        result["textData"] = this["decodeTextData"](bb);
        break;

      case 68:
        result["textDecoration"] = this["TextDecoration"][bb.readVarUint()];
        break;

      case 69:
        result["textTracking"] = bb.readVarFloat();
        break;

      case 70:
        result["textUserLayoutVersion"] = bb.readVarInt();
        break;

      case 71:
        result["letterSpacing"] = this["decodeNumber"](bb);
        break;

      case 72:
        result["lineHeight"] = this["decodeNumber"](bb);
        break;

      case 73:
        result["horizontalConstraint"] = this["ConstraintType"][bb.readVarUint()];
        break;

      case 74:
        result["verticalConstraint"] = this["ConstraintType"][bb.readVarUint()];
        break;

      case 75:
        var length = bb.readVarUint();
        var values = result["derivedSymbolData"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePixsoNode"](bb);
        break;

      case 76:
        result["derivedSymbolDataLayoutVersion"] = bb.readVarInt();
        break;

      case 77:
        result["componentKey"] = bb.readString();
        break;

      case 78:
        result["inheritEffectStyleID"] = this["decodeGUID"](bb);
        break;

      case 79:
        result["inheritExportStyleID"] = this["decodeGUID"](bb);
        break;

      case 80:
        result["inheritFillStyleID"] = this["decodeGUID"](bb);
        break;

      case 81:
        result["inheritFillStyleIDForBackground"] = this["decodeGUID"](bb);
        break;

      case 82:
        result["inheritFillStyleIDForStroke"] = this["decodeGUID"](bb);
        break;

      case 83:
        result["inheritGridStyleID"] = this["decodeGUID"](bb);
        break;

      case 84:
        result["inheritStrokeStyleID"] = this["decodeGUID"](bb);
        break;

      case 85:
        result["inheritTextStyleID"] = this["decodeGUID"](bb);
        break;

      case 86:
        result["interactionDuration"] = bb.readVarFloat();
        break;

      case 87:
        result["interactionMaintained"] = !!bb.readByte();
        break;

      case 88:
        result["overriddenSymbolID"] = this["decodeGUID"](bb);
        break;

      case 89:
        result["overrideKey"] = this["decodeGUID"](bb);
        break;

      case 90:
        result["keyTrigger"] = this["decodeKeyTrigger"](bb);
        break;

      case 91:
        result["navigationType"] = this["NavigationType"][bb.readVarUint()];
        break;

      case 92:
        result["interactionType"] = this["InteractionType"][bb.readVarUint()];
        break;

      case 93:
        result["connectionType"] = this["ConnectionType"][bb.readVarUint()];
        break;

      case 94:
        result["connectionURL"] = bb.readString();
        break;

      case 95:
        result["easingType"] = this["EasingType"][bb.readVarUint()];
        break;

      case 96:
        result["proportionsConstrained"] = !!bb.readByte();
        break;

      case 97:
        result["prototypeBackgroundColor"] = this["decodeColor"](bb);
        break;

      case 98:
        result["prototypeDevice"] = this["decodePrototypeDevice"](bb);
        break;

      case 99:
        var length = bb.readVarUint();
        var values = result["prototypeInteractions"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePrototypeInteraction"](bb);
        break;

      case 100:
        result["prototypeStartNodeID"] = this["decodeGUID"](bb);
        break;

      case 101:
        result["overlayBackgroundAppearance"] = this["decodeOverlayBackgroundAppearance"](bb);
        break;

      case 102:
        result["overlayBackgroundInteraction"] = this["OverlayBackgroundInteraction"][bb.readVarUint()];
        break;

      case 103:
        result["overlayPositionType"] = this["OverlayPositionType"][bb.readVarUint()];
        break;

      case 104:
        result["overlayRelativePosition"] = this["decodeVector"](bb);
        break;

      case 105:
        result["transitionDuration"] = bb.readVarFloat();
        break;

      case 106:
        result["transitionNodeID"] = this["decodeGUID"](bb);
        break;

      case 107:
        result["transitionPreserveScroll"] = !!bb.readByte();
        break;

      case 108:
        result["transitionShouldSmartAnimate"] = !!bb.readByte();
        break;

      case 109:
        result["transitionTimeout"] = bb.readVarFloat();
        break;

      case 110:
        result["transitionType"] = this["TransitionType"][bb.readVarUint()];
        break;

      case 111:
        result["scrollBehavior"] = this["ScrollBehavior"][bb.readVarUint()];
        break;

      case 112:
        result["scrollDirection"] = this["ScrollDirection"][bb.readVarUint()];
        break;

      case 113:
        result["rectangleBottomLeftCornerRadius"] = bb.readVarFloat();
        break;

      case 114:
        result["rectangleBottomRightCornerRadius"] = bb.readVarFloat();
        break;

      case 115:
        result["rectangleCornerRadiiIndependent"] = !!bb.readByte();
        break;

      case 116:
        result["rectangleCornerToolIndependent"] = !!bb.readByte();
        break;

      case 117:
        result["rectangleTopLeftCornerRadius"] = bb.readVarFloat();
        break;

      case 118:
        result["rectangleTopRightCornerRadius"] = bb.readVarFloat();
        break;

      case 119:
        result["frameMaskDisabled"] = !!bb.readByte();
        break;

      case 120:
        result["hyperlink"] = this["decodeHyperlink"](bb);
        break;

      case 121:
        result["sharedStyleMasterData"] = this["decodeSharedStyleMasterData"](bb);
        break;

      case 122:
        result["sharedStyleReference"] = this["decodeSharedStyleReference"](bb);
        break;

      case 123:
        result["autoRename"] = !!bb.readByte();
        break;

      case 124:
        result["handleMirroring"] = this["VectorMirror"][bb.readVarUint()];
        break;

      case 125:
        result["internalOnly"] = !!bb.readByte();
        break;

      case 126:
        result["isSoftDeletedStyle"] = !!bb.readByte();
        break;

      case 127:
        result["isNonUpdateable"] = !!bb.readByte();
        break;

      case 128:
        result["isPublishable"] = !!bb.readByte();
        break;

      case 129:
        result["publishFile"] = bb.readString();
        break;

      case 130:
        result["publishID"] = this["decodeGUID"](bb);
        break;

      case 131:
        result["publishedVersion"] = bb.readString();
        break;

      case 132:
        result["isSymbolPublishable"] = !!bb.readByte();
        break;

      case 133:
        result["sharedSymbolVersion"] = bb.readString();
        break;

      case 134:
        var length = bb.readVarUint();
        var values = result["ancestorPathBeforeDeletion"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 135:
        var length = bb.readVarUint();
        var values = result["guides"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGuide"](bb);
        break;

      case 136:
        var length = bb.readVarUint();
        var values = result["stateGroupPropertyValueOrders"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePropValueData"](bb);
        break;

      case 137:
        result["isStateGroup"] = !!bb.readByte();
        break;

      case 138:
        result["stackPaddingRight"] = bb.readVarFloat();
        break;

      case 139:
        result["stackPaddingLeft"] = bb.readVarFloat();
        break;

      case 140:
        result["stackPaddingTop"] = bb.readVarFloat();
        break;

      case 141:
        result["stackPaddingBottom"] = bb.readVarFloat();
        break;

      case 142:
        result["stackPrimarySizing"] = this["StackSize"][bb.readVarUint()];
        break;

      case 143:
        result["stackChildPrimarySizing"] = this["StackSize"][bb.readVarUint()];
        break;

      case 144:
        result["stackChildCounterSizing"] = this["StackSize"][bb.readVarUint()];
        break;

      case 145:
        result["stackPrimaryAlignItems"] = this["StackAlignItemMode"][bb.readVarUint()];
        break;

      case 146:
        result["stackCounterAlignItems"] = this["StackAlignItemMode"][bb.readVarUint()];
        break;

      case 147:
        result["prototypeStartPt"] = this["decodePrototypeStartPoint"](bb);
        break;

      case 148:
        result["dashCap"] = this["StrokeCap"][bb.readVarUint()];
        break;

      case 149:
        result["connectlineInfo"] = this["decodeConnectLineInfo"](bb);
        break;

      case 150:
        var length = bb.readVarUint();
        var values = result["objSnapConnline"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeObjSnapConnline"](bb);
        break;

      case 151:
        var length = bb.readVarUint();
        var values = result["connlineTextInfos"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeConnlineTextInfo"](bb);
        break;

      case 152:
        var length = bb.readVarUint();
        var values = result["vectorPaints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVectorPaint"](bb);
        break;

      case 153:
        var length = bb.readVarUint();
        var values = result["vectorStyles"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVectorStyle"](bb);
        break;

      case 154:
        result["borderTopWeight"] = bb.readVarFloat();
        break;

      case 155:
        result["borderBottomWeight"] = bb.readVarFloat();
        break;

      case 156:
        result["borderLeftWeight"] = bb.readVarFloat();
        break;

      case 157:
        result["borderRightWeight"] = bb.readVarFloat();
        break;

      case 158:
        result["borderStrokeWeightsIndependent"] = !!bb.readByte();
        break;

      case 159:
        var length = bb.readVarUint();
        var values = result["pluginData"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePluginData"](bb);
        break;

      case 160:
        result["showInSlice"] = !!bb.readByte();
        break;

      case 161:
        result["exportImageQuality"] = this["ExportImageQualityOp"][bb.readVarUint()];
        break;

      case 162:
        var length = bb.readVarUint();
        var values = result["strokePaddingPath"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePath"](bb);
        break;

      case 163:
        result["autoLayoutAbsolutePos"] = !!bb.readByte();
        break;

      case 164:
        result["autoLayoutItemReverseDraw"] = !!bb.readByte();
        break;

      case 165:
        var length = bb.readVarUint();
        var values = result["pluginRelaunchData"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePluginRelaunchData"](bb);
        break;

      case 166:
        result["autoLayoutIncludeBorders"] = !!bb.readByte();
        break;

      case 167:
        result["prodMode"] = this["decodeProdMode"](bb);
        break;

      case 168:
        result["exportCutPix"] = !!bb.readByte();
        break;

      case 169:
        result["exportKeepNameGroup"] = !!bb.readByte();
        break;

      case 170:
        result["textTruncation"] = this["TextTruncation"][bb.readVarUint()];
        break;

      case 171:
        result["maskType"] = this["MaskType"][bb.readVarUint()];
        break;

      case 172:
        result["leadingTrim"] = this["LeadingTrim"][bb.readVarUint()];
        break;

      case 173:
        result["hangingPunctuation"] = !!bb.readByte();
        break;

      case 174:
        result["hangingList"] = !!bb.readByte();
        break;

      case 175:
        result["fontVariantNumericFigure"] = this["FontVariantNumericFigure"][bb.readVarUint()];
        break;

      case 176:
        result["fontVariantNumericSpacing"] = this["FontVariantNumericSpacing"][bb.readVarUint()];
        break;

      case 177:
        result["fontVariantNumericFraction"] = this["FontVariantNumericFraction"][bb.readVarUint()];
        break;

      case 178:
        result["fontVariantPosition"] = this["FontVariantPosition"][bb.readVarUint()];
        break;

      case 179:
        var length = bb.readVarUint();
        var values = result["toggledOnOTFeatures"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["OpenTypeFeature"][bb.readVarUint()];
        break;

      case 180:
        var length = bb.readVarUint();
        var values = result["toggledOffOTFeatures"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["OpenTypeFeature"][bb.readVarUint()];
        break;

      case 181:
        result["maxLines"] = bb.readVarInt();
        break;

      case 182:
        result["sectionState"] = this["WorkState"][bb.readVarUint()];
        break;

      case 183:
        result["editInfo"] = this["decodeEditInfo"](bb);
        break;

      case 184:
        result["stackCounterSpacing"] = bb.readVarFloat();
        break;

      case 185:
        result["stackCounterAlignContent"] = this["StackAlign"][bb.readVarUint()];
        break;

      case 186:
        result["stackWrap"] = this["WrapMode"][bb.readVarUint()];
        break;

      case 187:
        result["minSize"] = this["decodeVector"](bb);
        break;

      case 188:
        result["maxSize"] = this["decodeVector"](bb);
        break;

      case 189:
        var length = bb.readVarUint();
        var values = result["componentPropDef"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeComponentPropDef"](bb);
        break;

      case 190:
        var length = bb.readVarUint();
        var values = result["componentPropRef"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeComponentPropRef"](bb);
        break;

      case 191:
        var length = bb.readVarUint();
        var values = result["componentPropAssignment"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeComponentPropAssignment"](bb);
        break;

      case 192:
        var length = bb.readVarUint();
        var values = result["symbolLinks"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeSymbolLink"](bb);
        break;

      case 193:
        result["description"] = bb.readString();
        break;

      case 194:
        result["exportNameByVariantProp"] = !!bb.readByte();
        break;

      case 195:
        result["propsAreBubbled"] = !!bb.readByte();
        break;

      case 196:
        result["showMask"] = !!bb.readByte();
        break;

      case 197:
        result["componentOverrideHierarchy"] = !!bb.readByte();
        break;

      case 198:
        var length = bb.readVarUint();
        var values = result["developerRelatedLinks"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDeveloperRelatedLink"](bb);
        break;

      case 199:
        var length = bb.readVarUint();
        var values = result["fontVariations"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeFontVariation"](bb);
        break;

      case 200:
        result["pathTextInfo"] = this["decodePathTextInfo"](bb);
        break;

      case 201:
        result["detachOpticalSizeFromFontSize"] = !!bb.readByte();
        break;

      case 202:
        result["radialRepeatData"] = this["decodeRadialRepeatData"](bb);
        break;

      case 203:
        result["overrideLevel"] = bb.readVarInt();
        break;

      case 204:
        result["variableData"] = this["decodeVariableData"](bb);
        break;

      case 205:
        result["variableConsumptionMap"] = this["decodeVariableDataMap"](bb);
        break;

      case 206:
        result["variableModeBySetMap"] = this["decodeVariableModeBySetMap"](bb);
        break;

      case 207:
        var length = bb.readVarUint();
        var values = result["variableSetModes"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableSetMode"](bb);
        break;

      case 208:
        result["variableSetID"] = this["decodeAssetID"](bb);
        break;

      case 209:
        result["variableResolvedType"] = this["VariableResolvedDataType"][bb.readVarUint()];
        break;

      case 210:
        result["variableDataValues"] = this["decodeVariableDataValues"](bb);
        break;

      case 211:
        result["variableTokenName"] = bb.readString();
        break;

      case 212:
        var length = bb.readVarUint();
        var values = result["variableScopes"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["VariableScope"][bb.readVarUint()];
        break;

      case 213:
        result["codeSyntax"] = this["decodeCodeSyntaxMap"](bb);
        break;

      case 214:
        result["backingVariableSetId"] = this["decodeAssetID"](bb);
        break;

      case 215:
        result["backingVariableId"] = this["decodeVariableIdOrVariableOverrideId"](bb);
        break;

      case 216:
        result["rootVariableKey"] = bb.readString();
        break;

      case 217:
        result["userFacingVersion"] = bb.readString();
        break;

      case 218:
        result["key"] = bb.readString();
        break;

      case 219:
        result["isSoftDeleted"] = !!bb.readByte();
        break;

      case 220:
        result["sortPosition"] = bb.readString();
        break;

      case 221:
        result["sourceLibraryKey"] = bb.readString();
        break;

      case 222:
        result["deliverInfo"] = this["decodeDeliverInfo"](bb);
        break;

      case 223:
        result["deformationTransform"] = this["decodeMatrix3f"](bb);
        break;

      case 224:
        var length = bb.readVarUint();
        var values = result["transformModifiers"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeTransformModifier"](bb);
        break;

      case 225:
        result["groupIncludeInvisible"] = !!bb.readByte();
        break;

      case 226:
        result["variableSymbolID"] = this["decodeGUID"](bb);
        break;

      case 227:
        var length = bb.readVarUint();
        var values = result["annotations"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeAnnotation"](bb);
        break;

      case 228:
        result["annotationCategories"] = this["decodeAnnotationCategories"](bb);
        break;

      case 229:
        result["gridRowAnchor"] = this["decodeGUID"](bb);
        break;

      case 230:
        result["gridColumnAnchor"] = this["decodeGUID"](bb);
        break;

      case 231:
        result["gridRowSpan"] = bb.readVarUint();
        break;

      case 232:
        result["gridColumnSpan"] = bb.readVarUint();
        break;

      case 233:
        result["gridChildVerticalAlign"] = this["GridChildAlign"][bb.readVarUint()];
        break;

      case 234:
        result["gridChildHorizontalAlign"] = this["GridChildAlign"][bb.readVarUint()];
        break;

      case 235:
        var length = bb.readVarUint();
        var values = result["gridRows"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 236:
        var length = bb.readVarUint();
        var values = result["gridColumns"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 237:
        var length = bb.readVarUint();
        var values = result["gridRowsSizing"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGridTrackSizing"](bb);
        break;

      case 238:
        var length = bb.readVarUint();
        var values = result["gridColumnsSizing"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGridTrackSizing"](bb);
        break;

      case 239:
        result["autoCornerRadius"] = !!bb.readByte();
        break;

      case 240:
        result["targetAspectRatio"] = this["decodeVector"](bb);
        break;

      case 241:
        result["aliasName"] = bb.readString();
        break;

      case 242:
        result["simplifyInstancePanels"] = !!bb.readByte();
        break;

      case 243:
        result["rotationOrigin"] = this["decodeVector"](bb);
        break;

      case 244:
        result["videoPlayback"] = this["decodeVideoPlayback"](bb);
        break;

      case 245:
        var length = bb.readVarUint();
        var values = result["variableWidths"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableWidthPoint"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePixsoNode"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["guidPath"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUIDPath"](value, bb);
  }

  var value = message["parentIndex"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeParentIndex"](value, bb);
  }

  var value = message["phase"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["NodePhase"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NodePhase\""); bb.writeVarUint(encoded);
  }

  var value = message["transform"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeMatrix"](value, bb);
  }

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["NodeType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NodeType\""); bb.writeVarUint(encoded);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeString(value);
  }

  var value = message["vectorData"];
  if (value != null) {
    bb.writeVarUint(8);
    this["encodeVectorData"](value, bb);
  }

  var value = message["version"];
  if (value != null) {
    bb.writeVarUint(9);
    bb.writeString(value);
  }

  var value = message["visible"];
  if (value != null) {
    bb.writeVarUint(10);
    bb.writeByte(value);
  }

  var value = message["count"];
  if (value != null) {
    bb.writeVarUint(11);
    bb.writeVarInt(value);
  }

  var value = message["size"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeVector"](value, bb);
  }

  var value = message["booleanOperation"];
  if (value != null) {
    bb.writeVarUint(13);
    var encoded = this["BooleanOperation"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"BooleanOperation\""); bb.writeVarUint(encoded);
  }

  var value = message["arcData"];
  if (value != null) {
    bb.writeVarUint(14);
    this["encodeArcData"](value, bb);
  }

  var value = message["blendMode"];
  if (value != null) {
    bb.writeVarUint(15);
    var encoded = this["BlendMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"BlendMode\""); bb.writeVarUint(encoded);
  }

  var value = message["cornerRadius"];
  if (value != null) {
    bb.writeVarUint(16);
    bb.writeVarFloat(value);
  }

  var value = message["cornerSmoothing"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeVarFloat(value);
  }

  var value = message["opacity"];
  if (value != null) {
    bb.writeVarUint(18);
    bb.writeVarFloat(value);
  }

  var value = message["locked"];
  if (value != null) {
    bb.writeVarUint(19);
    bb.writeByte(value);
  }

  var value = message["effects"];
  if (value != null) {
    bb.writeVarUint(20);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeEffect"](value, bb);
    }
  }

  var value = message["fillGeometry"];
  if (value != null) {
    bb.writeVarUint(21);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePath"](value, bb);
    }
  }

  var value = message["fillPaints"];
  if (value != null) {
    bb.writeVarUint(22);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePaint"](value, bb);
    }
  }

  var value = message["dashPattern"];
  if (value != null) {
    bb.writeVarUint(23);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }

  var value = message["stackCounterAlign"];
  if (value != null) {
    bb.writeVarUint(24);
    var encoded = this["StackCounterAlign"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackCounterAlign\""); bb.writeVarUint(encoded);
  }

  var value = message["stackCounterSizing"];
  if (value != null) {
    bb.writeVarUint(25);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["stackHeight"];
  if (value != null) {
    bb.writeVarUint(26);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["stackHorizontalPadding"];
  if (value != null) {
    bb.writeVarUint(27);
    bb.writeVarFloat(value);
  }

  var value = message["stackJustify"];
  if (value != null) {
    bb.writeVarUint(28);
    var encoded = this["StackJustify"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackJustify\""); bb.writeVarUint(encoded);
  }

  var value = message["stackMode"];
  if (value != null) {
    bb.writeVarUint(29);
    var encoded = this["StackMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackMode\""); bb.writeVarUint(encoded);
  }

  var value = message["stackPadding"];
  if (value != null) {
    bb.writeVarUint(30);
    bb.writeVarFloat(value);
  }

  var value = message["stackSpacing"];
  if (value != null) {
    bb.writeVarUint(31);
    bb.writeVarFloat(value);
  }

  var value = message["stackVerticalPadding"];
  if (value != null) {
    bb.writeVarUint(32);
    bb.writeVarFloat(value);
  }

  var value = message["stackWidth"];
  if (value != null) {
    bb.writeVarUint(33);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["strokeAlign"];
  if (value != null) {
    bb.writeVarUint(34);
    var encoded = this["StrokeAlign"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeAlign\""); bb.writeVarUint(encoded);
  }

  var value = message["strokeCap"];
  if (value != null) {
    bb.writeVarUint(35);
    var encoded = this["StrokeCap"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeCap\""); bb.writeVarUint(encoded);
  }

  var value = message["strokeGeometry"];
  if (value != null) {
    bb.writeVarUint(36);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePath"](value, bb);
    }
  }

  var value = message["strokeJoin"];
  if (value != null) {
    bb.writeVarUint(37);
    var encoded = this["StrokeJoin"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeJoin\""); bb.writeVarUint(encoded);
  }

  var value = message["strokePaints"];
  if (value != null) {
    bb.writeVarUint(38);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePaint"](value, bb);
    }
  }

  var value = message["strokeWeight"];
  if (value != null) {
    bb.writeVarUint(39);
    bb.writeVarFloat(value);
  }

  var value = message["styleDescription"];
  if (value != null) {
    bb.writeVarUint(40);
    bb.writeString(value);
  }

  var value = message["styleID"];
  if (value != null) {
    bb.writeVarUint(41);
    bb.writeVarInt(value);
  }

  var value = message["styleType"];
  if (value != null) {
    bb.writeVarUint(42);
    var encoded = this["StyleType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StyleType\""); bb.writeVarUint(encoded);
  }

  var value = message["symbolData"];
  if (value != null) {
    bb.writeVarUint(43);
    this["encodeSymbolData"](value, bb);
  }

  var value = message["symbolDescription"];
  if (value != null) {
    bb.writeVarUint(44);
    bb.writeString(value);
  }

  var value = message["layoutGrids"];
  if (value != null) {
    bb.writeVarUint(45);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeLayoutGrid"](value, bb);
    }
  }

  var value = message["mask"];
  if (value != null) {
    bb.writeVarUint(46);
    bb.writeByte(value);
  }

  var value = message["maskIsOutline"];
  if (value != null) {
    bb.writeVarUint(47);
    bb.writeByte(value);
  }

  var value = message["starInnerScale"];
  if (value != null) {
    bb.writeVarUint(48);
    bb.writeVarFloat(value);
  }

  var value = message["miterLimit"];
  if (value != null) {
    bb.writeVarUint(49);
    bb.writeVarFloat(value);
  }

  var value = message["backgroundColor"];
  if (value != null) {
    bb.writeVarUint(50);
    this["encodeColor"](value, bb);
  }

  var value = message["backgroundEnabled"];
  if (value != null) {
    bb.writeVarUint(51);
    bb.writeByte(value);
  }

  var value = message["backgroundOpacity"];
  if (value != null) {
    bb.writeVarUint(52);
    bb.writeVarFloat(value);
  }

  var value = message["backgroundPaints"];
  if (value != null) {
    bb.writeVarUint(53);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePaint"](value, bb);
    }
  }

  var value = message["exportBackgroundDisabled"];
  if (value != null) {
    bb.writeVarUint(54);
    bb.writeByte(value);
  }

  var value = message["exportContentsOnly"];
  if (value != null) {
    bb.writeVarUint(55);
    bb.writeByte(value);
  }

  var value = message["exportSettings"];
  if (value != null) {
    bb.writeVarUint(56);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeExportSettings"](value, bb);
    }
  }

  var value = message["exportTextAsSVGText"];
  if (value != null) {
    bb.writeVarUint(57);
    bb.writeByte(value);
  }

  var value = message["fontName"];
  if (value != null) {
    bb.writeVarUint(58);
    this["encodeFontName"](value, bb);
  }

  var value = message["fontSize"];
  if (value != null) {
    bb.writeVarUint(59);
    bb.writeVarFloat(value);
  }

  var value = message["fontVersion"];
  if (value != null) {
    bb.writeVarUint(60);
    bb.writeString(value);
  }

  var value = message["paragraphIndent"];
  if (value != null) {
    bb.writeVarUint(61);
    bb.writeVarFloat(value);
  }

  var value = message["paragraphSpacing"];
  if (value != null) {
    bb.writeVarUint(62);
    bb.writeVarFloat(value);
  }

  var value = message["textAlignHorizontal"];
  if (value != null) {
    bb.writeVarUint(63);
    var encoded = this["TextAlignHorizontal"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAlignHorizontal\""); bb.writeVarUint(encoded);
  }

  var value = message["textAlignVertical"];
  if (value != null) {
    bb.writeVarUint(64);
    var encoded = this["TextAlignVertical"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAlignVertical\""); bb.writeVarUint(encoded);
  }

  var value = message["textAutoResize"];
  if (value != null) {
    bb.writeVarUint(65);
    var encoded = this["TextAutoResize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAutoResize\""); bb.writeVarUint(encoded);
  }

  var value = message["textCase"];
  if (value != null) {
    bb.writeVarUint(66);
    var encoded = this["TextCase"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextCase\""); bb.writeVarUint(encoded);
  }

  var value = message["textData"];
  if (value != null) {
    bb.writeVarUint(67);
    this["encodeTextData"](value, bb);
  }

  var value = message["textDecoration"];
  if (value != null) {
    bb.writeVarUint(68);
    var encoded = this["TextDecoration"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextDecoration\""); bb.writeVarUint(encoded);
  }

  var value = message["textTracking"];
  if (value != null) {
    bb.writeVarUint(69);
    bb.writeVarFloat(value);
  }

  var value = message["textUserLayoutVersion"];
  if (value != null) {
    bb.writeVarUint(70);
    bb.writeVarInt(value);
  }

  var value = message["letterSpacing"];
  if (value != null) {
    bb.writeVarUint(71);
    this["encodeNumber"](value, bb);
  }

  var value = message["lineHeight"];
  if (value != null) {
    bb.writeVarUint(72);
    this["encodeNumber"](value, bb);
  }

  var value = message["horizontalConstraint"];
  if (value != null) {
    bb.writeVarUint(73);
    var encoded = this["ConstraintType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConstraintType\""); bb.writeVarUint(encoded);
  }

  var value = message["verticalConstraint"];
  if (value != null) {
    bb.writeVarUint(74);
    var encoded = this["ConstraintType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConstraintType\""); bb.writeVarUint(encoded);
  }

  var value = message["derivedSymbolData"];
  if (value != null) {
    bb.writeVarUint(75);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePixsoNode"](value, bb);
    }
  }

  var value = message["derivedSymbolDataLayoutVersion"];
  if (value != null) {
    bb.writeVarUint(76);
    bb.writeVarInt(value);
  }

  var value = message["componentKey"];
  if (value != null) {
    bb.writeVarUint(77);
    bb.writeString(value);
  }

  var value = message["inheritEffectStyleID"];
  if (value != null) {
    bb.writeVarUint(78);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritExportStyleID"];
  if (value != null) {
    bb.writeVarUint(79);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritFillStyleID"];
  if (value != null) {
    bb.writeVarUint(80);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritFillStyleIDForBackground"];
  if (value != null) {
    bb.writeVarUint(81);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritFillStyleIDForStroke"];
  if (value != null) {
    bb.writeVarUint(82);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritGridStyleID"];
  if (value != null) {
    bb.writeVarUint(83);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritStrokeStyleID"];
  if (value != null) {
    bb.writeVarUint(84);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritTextStyleID"];
  if (value != null) {
    bb.writeVarUint(85);
    this["encodeGUID"](value, bb);
  }

  var value = message["interactionDuration"];
  if (value != null) {
    bb.writeVarUint(86);
    bb.writeVarFloat(value);
  }

  var value = message["interactionMaintained"];
  if (value != null) {
    bb.writeVarUint(87);
    bb.writeByte(value);
  }

  var value = message["overriddenSymbolID"];
  if (value != null) {
    bb.writeVarUint(88);
    this["encodeGUID"](value, bb);
  }

  var value = message["overrideKey"];
  if (value != null) {
    bb.writeVarUint(89);
    this["encodeGUID"](value, bb);
  }

  var value = message["keyTrigger"];
  if (value != null) {
    bb.writeVarUint(90);
    this["encodeKeyTrigger"](value, bb);
  }

  var value = message["navigationType"];
  if (value != null) {
    bb.writeVarUint(91);
    var encoded = this["NavigationType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NavigationType\""); bb.writeVarUint(encoded);
  }

  var value = message["interactionType"];
  if (value != null) {
    bb.writeVarUint(92);
    var encoded = this["InteractionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"InteractionType\""); bb.writeVarUint(encoded);
  }

  var value = message["connectionType"];
  if (value != null) {
    bb.writeVarUint(93);
    var encoded = this["ConnectionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConnectionType\""); bb.writeVarUint(encoded);
  }

  var value = message["connectionURL"];
  if (value != null) {
    bb.writeVarUint(94);
    bb.writeString(value);
  }

  var value = message["easingType"];
  if (value != null) {
    bb.writeVarUint(95);
    var encoded = this["EasingType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"EasingType\""); bb.writeVarUint(encoded);
  }

  var value = message["proportionsConstrained"];
  if (value != null) {
    bb.writeVarUint(96);
    bb.writeByte(value);
  }

  var value = message["prototypeBackgroundColor"];
  if (value != null) {
    bb.writeVarUint(97);
    this["encodeColor"](value, bb);
  }

  var value = message["prototypeDevice"];
  if (value != null) {
    bb.writeVarUint(98);
    this["encodePrototypeDevice"](value, bb);
  }

  var value = message["prototypeInteractions"];
  if (value != null) {
    bb.writeVarUint(99);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePrototypeInteraction"](value, bb);
    }
  }

  var value = message["prototypeStartNodeID"];
  if (value != null) {
    bb.writeVarUint(100);
    this["encodeGUID"](value, bb);
  }

  var value = message["overlayBackgroundAppearance"];
  if (value != null) {
    bb.writeVarUint(101);
    this["encodeOverlayBackgroundAppearance"](value, bb);
  }

  var value = message["overlayBackgroundInteraction"];
  if (value != null) {
    bb.writeVarUint(102);
    var encoded = this["OverlayBackgroundInteraction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OverlayBackgroundInteraction\""); bb.writeVarUint(encoded);
  }

  var value = message["overlayPositionType"];
  if (value != null) {
    bb.writeVarUint(103);
    var encoded = this["OverlayPositionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OverlayPositionType\""); bb.writeVarUint(encoded);
  }

  var value = message["overlayRelativePosition"];
  if (value != null) {
    bb.writeVarUint(104);
    this["encodeVector"](value, bb);
  }

  var value = message["transitionDuration"];
  if (value != null) {
    bb.writeVarUint(105);
    bb.writeVarFloat(value);
  }

  var value = message["transitionNodeID"];
  if (value != null) {
    bb.writeVarUint(106);
    this["encodeGUID"](value, bb);
  }

  var value = message["transitionPreserveScroll"];
  if (value != null) {
    bb.writeVarUint(107);
    bb.writeByte(value);
  }

  var value = message["transitionShouldSmartAnimate"];
  if (value != null) {
    bb.writeVarUint(108);
    bb.writeByte(value);
  }

  var value = message["transitionTimeout"];
  if (value != null) {
    bb.writeVarUint(109);
    bb.writeVarFloat(value);
  }

  var value = message["transitionType"];
  if (value != null) {
    bb.writeVarUint(110);
    var encoded = this["TransitionType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TransitionType\""); bb.writeVarUint(encoded);
  }

  var value = message["scrollBehavior"];
  if (value != null) {
    bb.writeVarUint(111);
    var encoded = this["ScrollBehavior"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ScrollBehavior\""); bb.writeVarUint(encoded);
  }

  var value = message["scrollDirection"];
  if (value != null) {
    bb.writeVarUint(112);
    var encoded = this["ScrollDirection"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ScrollDirection\""); bb.writeVarUint(encoded);
  }

  var value = message["rectangleBottomLeftCornerRadius"];
  if (value != null) {
    bb.writeVarUint(113);
    bb.writeVarFloat(value);
  }

  var value = message["rectangleBottomRightCornerRadius"];
  if (value != null) {
    bb.writeVarUint(114);
    bb.writeVarFloat(value);
  }

  var value = message["rectangleCornerRadiiIndependent"];
  if (value != null) {
    bb.writeVarUint(115);
    bb.writeByte(value);
  }

  var value = message["rectangleCornerToolIndependent"];
  if (value != null) {
    bb.writeVarUint(116);
    bb.writeByte(value);
  }

  var value = message["rectangleTopLeftCornerRadius"];
  if (value != null) {
    bb.writeVarUint(117);
    bb.writeVarFloat(value);
  }

  var value = message["rectangleTopRightCornerRadius"];
  if (value != null) {
    bb.writeVarUint(118);
    bb.writeVarFloat(value);
  }

  var value = message["frameMaskDisabled"];
  if (value != null) {
    bb.writeVarUint(119);
    bb.writeByte(value);
  }

  var value = message["hyperlink"];
  if (value != null) {
    bb.writeVarUint(120);
    this["encodeHyperlink"](value, bb);
  }

  var value = message["sharedStyleMasterData"];
  if (value != null) {
    bb.writeVarUint(121);
    this["encodeSharedStyleMasterData"](value, bb);
  }

  var value = message["sharedStyleReference"];
  if (value != null) {
    bb.writeVarUint(122);
    this["encodeSharedStyleReference"](value, bb);
  }

  var value = message["autoRename"];
  if (value != null) {
    bb.writeVarUint(123);
    bb.writeByte(value);
  }

  var value = message["handleMirroring"];
  if (value != null) {
    bb.writeVarUint(124);
    var encoded = this["VectorMirror"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VectorMirror\""); bb.writeVarUint(encoded);
  }

  var value = message["internalOnly"];
  if (value != null) {
    bb.writeVarUint(125);
    bb.writeByte(value);
  }

  var value = message["isSoftDeletedStyle"];
  if (value != null) {
    bb.writeVarUint(126);
    bb.writeByte(value);
  }

  var value = message["isNonUpdateable"];
  if (value != null) {
    bb.writeVarUint(127);
    bb.writeByte(value);
  }

  var value = message["isPublishable"];
  if (value != null) {
    bb.writeVarUint(128);
    bb.writeByte(value);
  }

  var value = message["publishFile"];
  if (value != null) {
    bb.writeVarUint(129);
    bb.writeString(value);
  }

  var value = message["publishID"];
  if (value != null) {
    bb.writeVarUint(130);
    this["encodeGUID"](value, bb);
  }

  var value = message["publishedVersion"];
  if (value != null) {
    bb.writeVarUint(131);
    bb.writeString(value);
  }

  var value = message["isSymbolPublishable"];
  if (value != null) {
    bb.writeVarUint(132);
    bb.writeByte(value);
  }

  var value = message["sharedSymbolVersion"];
  if (value != null) {
    bb.writeVarUint(133);
    bb.writeString(value);
  }

  var value = message["ancestorPathBeforeDeletion"];
  if (value != null) {
    bb.writeVarUint(134);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["guides"];
  if (value != null) {
    bb.writeVarUint(135);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGuide"](value, bb);
    }
  }

  var value = message["stateGroupPropertyValueOrders"];
  if (value != null) {
    bb.writeVarUint(136);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePropValueData"](value, bb);
    }
  }

  var value = message["isStateGroup"];
  if (value != null) {
    bb.writeVarUint(137);
    bb.writeByte(value);
  }

  var value = message["stackPaddingRight"];
  if (value != null) {
    bb.writeVarUint(138);
    bb.writeVarFloat(value);
  }

  var value = message["stackPaddingLeft"];
  if (value != null) {
    bb.writeVarUint(139);
    bb.writeVarFloat(value);
  }

  var value = message["stackPaddingTop"];
  if (value != null) {
    bb.writeVarUint(140);
    bb.writeVarFloat(value);
  }

  var value = message["stackPaddingBottom"];
  if (value != null) {
    bb.writeVarUint(141);
    bb.writeVarFloat(value);
  }

  var value = message["stackPrimarySizing"];
  if (value != null) {
    bb.writeVarUint(142);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["stackChildPrimarySizing"];
  if (value != null) {
    bb.writeVarUint(143);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["stackChildCounterSizing"];
  if (value != null) {
    bb.writeVarUint(144);
    var encoded = this["StackSize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackSize\""); bb.writeVarUint(encoded);
  }

  var value = message["stackPrimaryAlignItems"];
  if (value != null) {
    bb.writeVarUint(145);
    var encoded = this["StackAlignItemMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackAlignItemMode\""); bb.writeVarUint(encoded);
  }

  var value = message["stackCounterAlignItems"];
  if (value != null) {
    bb.writeVarUint(146);
    var encoded = this["StackAlignItemMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackAlignItemMode\""); bb.writeVarUint(encoded);
  }

  var value = message["prototypeStartPt"];
  if (value != null) {
    bb.writeVarUint(147);
    this["encodePrototypeStartPoint"](value, bb);
  }

  var value = message["dashCap"];
  if (value != null) {
    bb.writeVarUint(148);
    var encoded = this["StrokeCap"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeCap\""); bb.writeVarUint(encoded);
  }

  var value = message["connectlineInfo"];
  if (value != null) {
    bb.writeVarUint(149);
    this["encodeConnectLineInfo"](value, bb);
  }

  var value = message["objSnapConnline"];
  if (value != null) {
    bb.writeVarUint(150);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeObjSnapConnline"](value, bb);
    }
  }

  var value = message["connlineTextInfos"];
  if (value != null) {
    bb.writeVarUint(151);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeConnlineTextInfo"](value, bb);
    }
  }

  var value = message["vectorPaints"];
  if (value != null) {
    bb.writeVarUint(152);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVectorPaint"](value, bb);
    }
  }

  var value = message["vectorStyles"];
  if (value != null) {
    bb.writeVarUint(153);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVectorStyle"](value, bb);
    }
  }

  var value = message["borderTopWeight"];
  if (value != null) {
    bb.writeVarUint(154);
    bb.writeVarFloat(value);
  }

  var value = message["borderBottomWeight"];
  if (value != null) {
    bb.writeVarUint(155);
    bb.writeVarFloat(value);
  }

  var value = message["borderLeftWeight"];
  if (value != null) {
    bb.writeVarUint(156);
    bb.writeVarFloat(value);
  }

  var value = message["borderRightWeight"];
  if (value != null) {
    bb.writeVarUint(157);
    bb.writeVarFloat(value);
  }

  var value = message["borderStrokeWeightsIndependent"];
  if (value != null) {
    bb.writeVarUint(158);
    bb.writeByte(value);
  }

  var value = message["pluginData"];
  if (value != null) {
    bb.writeVarUint(159);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePluginData"](value, bb);
    }
  }

  var value = message["showInSlice"];
  if (value != null) {
    bb.writeVarUint(160);
    bb.writeByte(value);
  }

  var value = message["exportImageQuality"];
  if (value != null) {
    bb.writeVarUint(161);
    var encoded = this["ExportImageQualityOp"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ExportImageQualityOp\""); bb.writeVarUint(encoded);
  }

  var value = message["strokePaddingPath"];
  if (value != null) {
    bb.writeVarUint(162);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePath"](value, bb);
    }
  }

  var value = message["autoLayoutAbsolutePos"];
  if (value != null) {
    bb.writeVarUint(163);
    bb.writeByte(value);
  }

  var value = message["autoLayoutItemReverseDraw"];
  if (value != null) {
    bb.writeVarUint(164);
    bb.writeByte(value);
  }

  var value = message["pluginRelaunchData"];
  if (value != null) {
    bb.writeVarUint(165);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePluginRelaunchData"](value, bb);
    }
  }

  var value = message["autoLayoutIncludeBorders"];
  if (value != null) {
    bb.writeVarUint(166);
    bb.writeByte(value);
  }

  var value = message["prodMode"];
  if (value != null) {
    bb.writeVarUint(167);
    this["encodeProdMode"](value, bb);
  }

  var value = message["exportCutPix"];
  if (value != null) {
    bb.writeVarUint(168);
    bb.writeByte(value);
  }

  var value = message["exportKeepNameGroup"];
  if (value != null) {
    bb.writeVarUint(169);
    bb.writeByte(value);
  }

  var value = message["textTruncation"];
  if (value != null) {
    bb.writeVarUint(170);
    var encoded = this["TextTruncation"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextTruncation\""); bb.writeVarUint(encoded);
  }

  var value = message["maskType"];
  if (value != null) {
    bb.writeVarUint(171);
    var encoded = this["MaskType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"MaskType\""); bb.writeVarUint(encoded);
  }

  var value = message["leadingTrim"];
  if (value != null) {
    bb.writeVarUint(172);
    var encoded = this["LeadingTrim"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"LeadingTrim\""); bb.writeVarUint(encoded);
  }

  var value = message["hangingPunctuation"];
  if (value != null) {
    bb.writeVarUint(173);
    bb.writeByte(value);
  }

  var value = message["hangingList"];
  if (value != null) {
    bb.writeVarUint(174);
    bb.writeByte(value);
  }

  var value = message["fontVariantNumericFigure"];
  if (value != null) {
    bb.writeVarUint(175);
    var encoded = this["FontVariantNumericFigure"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericFigure\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantNumericSpacing"];
  if (value != null) {
    bb.writeVarUint(176);
    var encoded = this["FontVariantNumericSpacing"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericSpacing\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantNumericFraction"];
  if (value != null) {
    bb.writeVarUint(177);
    var encoded = this["FontVariantNumericFraction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericFraction\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantPosition"];
  if (value != null) {
    bb.writeVarUint(178);
    var encoded = this["FontVariantPosition"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantPosition\""); bb.writeVarUint(encoded);
  }

  var value = message["toggledOnOTFeatures"];
  if (value != null) {
    bb.writeVarUint(179);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["OpenTypeFeature"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OpenTypeFeature\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["toggledOffOTFeatures"];
  if (value != null) {
    bb.writeVarUint(180);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["OpenTypeFeature"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OpenTypeFeature\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["maxLines"];
  if (value != null) {
    bb.writeVarUint(181);
    bb.writeVarInt(value);
  }

  var value = message["sectionState"];
  if (value != null) {
    bb.writeVarUint(182);
    var encoded = this["WorkState"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"WorkState\""); bb.writeVarUint(encoded);
  }

  var value = message["editInfo"];
  if (value != null) {
    bb.writeVarUint(183);
    this["encodeEditInfo"](value, bb);
  }

  var value = message["stackCounterSpacing"];
  if (value != null) {
    bb.writeVarUint(184);
    bb.writeVarFloat(value);
  }

  var value = message["stackCounterAlignContent"];
  if (value != null) {
    bb.writeVarUint(185);
    var encoded = this["StackAlign"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StackAlign\""); bb.writeVarUint(encoded);
  }

  var value = message["stackWrap"];
  if (value != null) {
    bb.writeVarUint(186);
    var encoded = this["WrapMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"WrapMode\""); bb.writeVarUint(encoded);
  }

  var value = message["minSize"];
  if (value != null) {
    bb.writeVarUint(187);
    this["encodeVector"](value, bb);
  }

  var value = message["maxSize"];
  if (value != null) {
    bb.writeVarUint(188);
    this["encodeVector"](value, bb);
  }

  var value = message["componentPropDef"];
  if (value != null) {
    bb.writeVarUint(189);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeComponentPropDef"](value, bb);
    }
  }

  var value = message["componentPropRef"];
  if (value != null) {
    bb.writeVarUint(190);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeComponentPropRef"](value, bb);
    }
  }

  var value = message["componentPropAssignment"];
  if (value != null) {
    bb.writeVarUint(191);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeComponentPropAssignment"](value, bb);
    }
  }

  var value = message["symbolLinks"];
  if (value != null) {
    bb.writeVarUint(192);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeSymbolLink"](value, bb);
    }
  }

  var value = message["description"];
  if (value != null) {
    bb.writeVarUint(193);
    bb.writeString(value);
  }

  var value = message["exportNameByVariantProp"];
  if (value != null) {
    bb.writeVarUint(194);
    bb.writeByte(value);
  }

  var value = message["propsAreBubbled"];
  if (value != null) {
    bb.writeVarUint(195);
    bb.writeByte(value);
  }

  var value = message["showMask"];
  if (value != null) {
    bb.writeVarUint(196);
    bb.writeByte(value);
  }

  var value = message["componentOverrideHierarchy"];
  if (value != null) {
    bb.writeVarUint(197);
    bb.writeByte(value);
  }

  var value = message["developerRelatedLinks"];
  if (value != null) {
    bb.writeVarUint(198);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDeveloperRelatedLink"](value, bb);
    }
  }

  var value = message["fontVariations"];
  if (value != null) {
    bb.writeVarUint(199);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeFontVariation"](value, bb);
    }
  }

  var value = message["pathTextInfo"];
  if (value != null) {
    bb.writeVarUint(200);
    this["encodePathTextInfo"](value, bb);
  }

  var value = message["detachOpticalSizeFromFontSize"];
  if (value != null) {
    bb.writeVarUint(201);
    bb.writeByte(value);
  }

  var value = message["radialRepeatData"];
  if (value != null) {
    bb.writeVarUint(202);
    this["encodeRadialRepeatData"](value, bb);
  }

  var value = message["overrideLevel"];
  if (value != null) {
    bb.writeVarUint(203);
    bb.writeVarInt(value);
  }

  var value = message["variableData"];
  if (value != null) {
    bb.writeVarUint(204);
    this["encodeVariableData"](value, bb);
  }

  var value = message["variableConsumptionMap"];
  if (value != null) {
    bb.writeVarUint(205);
    this["encodeVariableDataMap"](value, bb);
  }

  var value = message["variableModeBySetMap"];
  if (value != null) {
    bb.writeVarUint(206);
    this["encodeVariableModeBySetMap"](value, bb);
  }

  var value = message["variableSetModes"];
  if (value != null) {
    bb.writeVarUint(207);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableSetMode"](value, bb);
    }
  }

  var value = message["variableSetID"];
  if (value != null) {
    bb.writeVarUint(208);
    this["encodeAssetID"](value, bb);
  }

  var value = message["variableResolvedType"];
  if (value != null) {
    bb.writeVarUint(209);
    var encoded = this["VariableResolvedDataType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VariableResolvedDataType\""); bb.writeVarUint(encoded);
  }

  var value = message["variableDataValues"];
  if (value != null) {
    bb.writeVarUint(210);
    this["encodeVariableDataValues"](value, bb);
  }

  var value = message["variableTokenName"];
  if (value != null) {
    bb.writeVarUint(211);
    bb.writeString(value);
  }

  var value = message["variableScopes"];
  if (value != null) {
    bb.writeVarUint(212);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["VariableScope"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VariableScope\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["codeSyntax"];
  if (value != null) {
    bb.writeVarUint(213);
    this["encodeCodeSyntaxMap"](value, bb);
  }

  var value = message["backingVariableSetId"];
  if (value != null) {
    bb.writeVarUint(214);
    this["encodeAssetID"](value, bb);
  }

  var value = message["backingVariableId"];
  if (value != null) {
    bb.writeVarUint(215);
    this["encodeVariableIdOrVariableOverrideId"](value, bb);
  }

  var value = message["rootVariableKey"];
  if (value != null) {
    bb.writeVarUint(216);
    bb.writeString(value);
  }

  var value = message["userFacingVersion"];
  if (value != null) {
    bb.writeVarUint(217);
    bb.writeString(value);
  }

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(218);
    bb.writeString(value);
  }

  var value = message["isSoftDeleted"];
  if (value != null) {
    bb.writeVarUint(219);
    bb.writeByte(value);
  }

  var value = message["sortPosition"];
  if (value != null) {
    bb.writeVarUint(220);
    bb.writeString(value);
  }

  var value = message["sourceLibraryKey"];
  if (value != null) {
    bb.writeVarUint(221);
    bb.writeString(value);
  }

  var value = message["deliverInfo"];
  if (value != null) {
    bb.writeVarUint(222);
    this["encodeDeliverInfo"](value, bb);
  }

  var value = message["deformationTransform"];
  if (value != null) {
    bb.writeVarUint(223);
    this["encodeMatrix3f"](value, bb);
  }

  var value = message["transformModifiers"];
  if (value != null) {
    bb.writeVarUint(224);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeTransformModifier"](value, bb);
    }
  }

  var value = message["groupIncludeInvisible"];
  if (value != null) {
    bb.writeVarUint(225);
    bb.writeByte(value);
  }

  var value = message["variableSymbolID"];
  if (value != null) {
    bb.writeVarUint(226);
    this["encodeGUID"](value, bb);
  }

  var value = message["annotations"];
  if (value != null) {
    bb.writeVarUint(227);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeAnnotation"](value, bb);
    }
  }

  var value = message["annotationCategories"];
  if (value != null) {
    bb.writeVarUint(228);
    this["encodeAnnotationCategories"](value, bb);
  }

  var value = message["gridRowAnchor"];
  if (value != null) {
    bb.writeVarUint(229);
    this["encodeGUID"](value, bb);
  }

  var value = message["gridColumnAnchor"];
  if (value != null) {
    bb.writeVarUint(230);
    this["encodeGUID"](value, bb);
  }

  var value = message["gridRowSpan"];
  if (value != null) {
    bb.writeVarUint(231);
    bb.writeVarUint(value);
  }

  var value = message["gridColumnSpan"];
  if (value != null) {
    bb.writeVarUint(232);
    bb.writeVarUint(value);
  }

  var value = message["gridChildVerticalAlign"];
  if (value != null) {
    bb.writeVarUint(233);
    var encoded = this["GridChildAlign"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"GridChildAlign\""); bb.writeVarUint(encoded);
  }

  var value = message["gridChildHorizontalAlign"];
  if (value != null) {
    bb.writeVarUint(234);
    var encoded = this["GridChildAlign"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"GridChildAlign\""); bb.writeVarUint(encoded);
  }

  var value = message["gridRows"];
  if (value != null) {
    bb.writeVarUint(235);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["gridColumns"];
  if (value != null) {
    bb.writeVarUint(236);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["gridRowsSizing"];
  if (value != null) {
    bb.writeVarUint(237);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGridTrackSizing"](value, bb);
    }
  }

  var value = message["gridColumnsSizing"];
  if (value != null) {
    bb.writeVarUint(238);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGridTrackSizing"](value, bb);
    }
  }

  var value = message["autoCornerRadius"];
  if (value != null) {
    bb.writeVarUint(239);
    bb.writeByte(value);
  }

  var value = message["targetAspectRatio"];
  if (value != null) {
    bb.writeVarUint(240);
    this["encodeVector"](value, bb);
  }

  var value = message["aliasName"];
  if (value != null) {
    bb.writeVarUint(241);
    bb.writeString(value);
  }

  var value = message["simplifyInstancePanels"];
  if (value != null) {
    bb.writeVarUint(242);
    bb.writeByte(value);
  }

  var value = message["rotationOrigin"];
  if (value != null) {
    bb.writeVarUint(243);
    this["encodeVector"](value, bb);
  }

  var value = message["videoPlayback"];
  if (value != null) {
    bb.writeVarUint(244);
    this["encodeVideoPlayback"](value, bb);
  }

  var value = message["variableWidths"];
  if (value != null) {
    bb.writeVarUint(245);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableWidthPoint"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdMode"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["textStyle"] = this["decodeProdTextStyle"](bb);
        break;

      case 2:
        result["navigationItemInterval"] = bb.readVarFloat();
        break;

      case 3:
        result["prodContent"] = bb.readString();
        break;

      case 4:
        result["hostIndex"] = this["decodeParentIndex"](bb);
        break;

      case 5:
        result["tableRowCount"] = bb.readVarInt();
        break;

      case 6:
        result["tableColCount"] = bb.readVarInt();
        break;

      case 7:
        result["dropListOptionSelectID"] = this["decodeGUID"](bb);
        break;

      case 8:
        result["dropListExpand"] = !!bb.readByte();
        break;

      case 9:
        result["activeTextStyle"] = this["decodeProdTextStyle"](bb);
        break;

      case 10:
        result["tableSize"] = this["decodeVector"](bb);
        break;

      case 11:
        result["tableCellFillPaint"] = this["decodePaint"](bb);
        break;

      case 12:
        result["navigationItemSize"] = this["decodeVector"](bb);
        break;

      case 13:
        result["navigationOptionExpand"] = !!bb.readByte();
        break;

      case 14:
        result["componentLibrarySwitch"] = !!bb.readByte();
        break;

      case 15:
        result["scoreBar"] = this["decodeProdScoreBar"](bb);
        break;

      case 16:
        result["navigationItemRatio"] = bb.readVarFloat();
        break;

      case 17:
        result["dragBar"] = this["decodeProdDragBar"](bb);
        break;

      case 18:
        result["tableCell"] = this["decodeProdTableCell"](bb);
        break;

      case 19:
        result["tableBorderStyle"] = bb.readVarInt();
        break;

      case 20:
        result["embeddedIconPositionFlag"] = bb.readVarInt();
        break;

      case 21:
        result["recordHeight"] = bb.readVarFloat();
        break;

      case 22:
        result["selectForm"] = bb.readVarInt();
        break;

      case 23:
        result["layoutMethod"] = bb.readVarInt();
        break;

      case 24:
        result["layerPosition"] = bb.readVarInt();
        break;

      case 25:
        result["viewportOrientation"] = this["ProdViewportOrientation"][bb.readVarUint()];
        break;

      case 26:
        var length = bb.readVarUint();
        var values = result["vNodeType"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["NodeType"][bb.readVarUint()];
        break;

      case 27:
        result["stringIconSVG"] = bb.readString();
        break;

      case 28:
        result["tableHeaderVisible"] = !!bb.readByte();
        break;

      case 29:
        result["recordWidth"] = bb.readVarFloat();
        break;

      case 30:
        result["recodeCount"] = bb.readVarInt();
        break;

      case 31:
        result["selectIndex"] = bb.readVarInt();
        break;

      case 32:
        result["layoutParam"] = this["decodeProdLayoutParam"](bb);
        break;

      case 33:
        result["blockStyleType"] = this["ProdBlockStyleType"][bb.readVarUint()];
        break;

      case 34:
        result["distance"] = bb.readVarFloat();
        break;

      case 35:
        result["hoverTrigger"] = !!bb.readByte();
        break;

      case 36:
        result["fitContent"] = !!bb.readByte();
        break;

      case 37:
        result["stringIconName"] = bb.readString();
        break;

      case 38:
        result["twoDimChart"] = this["decodeProdTwoDimChart"](bb);
        break;

      case 39:
        var length = bb.readVarUint();
        var values = result["extraGuids"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 40:
        result["tableSelectColVisible"] = !!bb.readByte();
        break;

      case 41:
        result["frameScrollBarVisible"] = this["ScrollBar"][bb.readVarUint()];
        break;

      case 42:
        result["checkBoxState"] = bb.readVarInt();
        break;

      case 43:
        result["componentState"] = this["ComponentStateType"][bb.readVarUint()];
        break;

      case 44:
        result["iconSwitch"] = !!bb.readByte();
        break;

      case 45:
        result["checkBoxSwitch"] = !!bb.readByte();
        break;

      case 46:
        result["flodingSymbolSwitch"] = !!bb.readByte();
        break;

      case 47:
        result["checkBoxHited"] = !!bb.readByte();
        break;

      case 48:
        result["layerlndent"] = bb.readVarFloat();
        break;

      case 49:
        result["foldingSymbolType"] = bb.readVarInt();
        break;

      case 50:
        var length = bb.readVarUint();
        var values = result["blockMarkerIds"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 51:
        result["blockMarkerParams"] = this["decodeBlockMarkerParams"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdMode"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["textStyle"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeProdTextStyle"](value, bb);
  }

  var value = message["navigationItemInterval"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["prodContent"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["hostIndex"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeParentIndex"](value, bb);
  }

  var value = message["tableRowCount"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarInt(value);
  }

  var value = message["tableColCount"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeVarInt(value);
  }

  var value = message["dropListOptionSelectID"];
  if (value != null) {
    bb.writeVarUint(7);
    this["encodeGUID"](value, bb);
  }

  var value = message["dropListExpand"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeByte(value);
  }

  var value = message["activeTextStyle"];
  if (value != null) {
    bb.writeVarUint(9);
    this["encodeProdTextStyle"](value, bb);
  }

  var value = message["tableSize"];
  if (value != null) {
    bb.writeVarUint(10);
    this["encodeVector"](value, bb);
  }

  var value = message["tableCellFillPaint"];
  if (value != null) {
    bb.writeVarUint(11);
    this["encodePaint"](value, bb);
  }

  var value = message["navigationItemSize"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeVector"](value, bb);
  }

  var value = message["navigationOptionExpand"];
  if (value != null) {
    bb.writeVarUint(13);
    bb.writeByte(value);
  }

  var value = message["componentLibrarySwitch"];
  if (value != null) {
    bb.writeVarUint(14);
    bb.writeByte(value);
  }

  var value = message["scoreBar"];
  if (value != null) {
    bb.writeVarUint(15);
    this["encodeProdScoreBar"](value, bb);
  }

  var value = message["navigationItemRatio"];
  if (value != null) {
    bb.writeVarUint(16);
    bb.writeVarFloat(value);
  }

  var value = message["dragBar"];
  if (value != null) {
    bb.writeVarUint(17);
    this["encodeProdDragBar"](value, bb);
  }

  var value = message["tableCell"];
  if (value != null) {
    bb.writeVarUint(18);
    this["encodeProdTableCell"](value, bb);
  }

  var value = message["tableBorderStyle"];
  if (value != null) {
    bb.writeVarUint(19);
    bb.writeVarInt(value);
  }

  var value = message["embeddedIconPositionFlag"];
  if (value != null) {
    bb.writeVarUint(20);
    bb.writeVarInt(value);
  }

  var value = message["recordHeight"];
  if (value != null) {
    bb.writeVarUint(21);
    bb.writeVarFloat(value);
  }

  var value = message["selectForm"];
  if (value != null) {
    bb.writeVarUint(22);
    bb.writeVarInt(value);
  }

  var value = message["layoutMethod"];
  if (value != null) {
    bb.writeVarUint(23);
    bb.writeVarInt(value);
  }

  var value = message["layerPosition"];
  if (value != null) {
    bb.writeVarUint(24);
    bb.writeVarInt(value);
  }

  var value = message["viewportOrientation"];
  if (value != null) {
    bb.writeVarUint(25);
    var encoded = this["ProdViewportOrientation"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdViewportOrientation\""); bb.writeVarUint(encoded);
  }

  var value = message["vNodeType"];
  if (value != null) {
    bb.writeVarUint(26);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["NodeType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NodeType\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["stringIconSVG"];
  if (value != null) {
    bb.writeVarUint(27);
    bb.writeString(value);
  }

  var value = message["tableHeaderVisible"];
  if (value != null) {
    bb.writeVarUint(28);
    bb.writeByte(value);
  }

  var value = message["recordWidth"];
  if (value != null) {
    bb.writeVarUint(29);
    bb.writeVarFloat(value);
  }

  var value = message["recodeCount"];
  if (value != null) {
    bb.writeVarUint(30);
    bb.writeVarInt(value);
  }

  var value = message["selectIndex"];
  if (value != null) {
    bb.writeVarUint(31);
    bb.writeVarInt(value);
  }

  var value = message["layoutParam"];
  if (value != null) {
    bb.writeVarUint(32);
    this["encodeProdLayoutParam"](value, bb);
  }

  var value = message["blockStyleType"];
  if (value != null) {
    bb.writeVarUint(33);
    var encoded = this["ProdBlockStyleType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdBlockStyleType\""); bb.writeVarUint(encoded);
  }

  var value = message["distance"];
  if (value != null) {
    bb.writeVarUint(34);
    bb.writeVarFloat(value);
  }

  var value = message["hoverTrigger"];
  if (value != null) {
    bb.writeVarUint(35);
    bb.writeByte(value);
  }

  var value = message["fitContent"];
  if (value != null) {
    bb.writeVarUint(36);
    bb.writeByte(value);
  }

  var value = message["stringIconName"];
  if (value != null) {
    bb.writeVarUint(37);
    bb.writeString(value);
  }

  var value = message["twoDimChart"];
  if (value != null) {
    bb.writeVarUint(38);
    this["encodeProdTwoDimChart"](value, bb);
  }

  var value = message["extraGuids"];
  if (value != null) {
    bb.writeVarUint(39);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["tableSelectColVisible"];
  if (value != null) {
    bb.writeVarUint(40);
    bb.writeByte(value);
  }

  var value = message["frameScrollBarVisible"];
  if (value != null) {
    bb.writeVarUint(41);
    var encoded = this["ScrollBar"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ScrollBar\""); bb.writeVarUint(encoded);
  }

  var value = message["checkBoxState"];
  if (value != null) {
    bb.writeVarUint(42);
    bb.writeVarInt(value);
  }

  var value = message["componentState"];
  if (value != null) {
    bb.writeVarUint(43);
    var encoded = this["ComponentStateType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ComponentStateType\""); bb.writeVarUint(encoded);
  }

  var value = message["iconSwitch"];
  if (value != null) {
    bb.writeVarUint(44);
    bb.writeByte(value);
  }

  var value = message["checkBoxSwitch"];
  if (value != null) {
    bb.writeVarUint(45);
    bb.writeByte(value);
  }

  var value = message["flodingSymbolSwitch"];
  if (value != null) {
    bb.writeVarUint(46);
    bb.writeByte(value);
  }

  var value = message["checkBoxHited"];
  if (value != null) {
    bb.writeVarUint(47);
    bb.writeByte(value);
  }

  var value = message["layerlndent"];
  if (value != null) {
    bb.writeVarUint(48);
    bb.writeVarFloat(value);
  }

  var value = message["foldingSymbolType"];
  if (value != null) {
    bb.writeVarUint(49);
    bb.writeVarInt(value);
  }

  var value = message["blockMarkerIds"];
  if (value != null) {
    bb.writeVarUint(50);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["blockMarkerParams"];
  if (value != null) {
    bb.writeVarUint(51);
    this["encodeBlockMarkerParams"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeBlockMarkerParams"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["relatedMarkerId"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["markerSide"] = this["MarkerSide"][bb.readVarUint()];
        break;

      case 3:
        result["boundNodeId"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["markerIndex"] = bb.readVarInt();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeBlockMarkerParams"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["relatedMarkerId"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["markerSide"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["MarkerSide"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"MarkerSide\""); bb.writeVarUint(encoded);
  }

  var value = message["boundNodeId"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["markerIndex"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdLayoutParam"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["layoutMode"] = this["ProdLayoutMode"][bb.readVarUint()];
        break;

      case 2:
        result["witdhMode"] = this["ProdLayoutSizeMode"][bb.readVarUint()];
        break;

      case 3:
        result["heightMode"] = this["ProdLayoutSizeMode"][bb.readVarUint()];
        break;

      case 4:
        result["margin"] = this["decodeProdLayoutInterval"](bb);
        break;

      case 5:
        result["padding"] = this["decodeProdLayoutInterval"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdLayoutParam"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["layoutMode"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ProdLayoutMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdLayoutMode\""); bb.writeVarUint(encoded);
  }

  var value = message["witdhMode"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["ProdLayoutSizeMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdLayoutSizeMode\""); bb.writeVarUint(encoded);
  }

  var value = message["heightMode"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["ProdLayoutSizeMode"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdLayoutSizeMode\""); bb.writeVarUint(encoded);
  }

  var value = message["margin"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeProdLayoutInterval"](value, bb);
  }

  var value = message["padding"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeProdLayoutInterval"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdLayoutInterval"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["left"] = bb.readVarFloat();
        break;

      case 2:
        result["top"] = bb.readVarFloat();
        break;

      case 3:
        result["right"] = bb.readVarFloat();
        break;

      case 4:
        result["bottom"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdLayoutInterval"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["left"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["top"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["right"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["bottom"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdAdjustSize"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["adjustSizeType"] = this["ProdAdjustSizeType"][bb.readVarUint()];
        break;

      case 2:
        result["baseDirection"] = this["ProdAdjustBaseType"][bb.readVarUint()];
        break;

      case 3:
        result["width"] = bb.readVarFloat();
        break;

      case 4:
        result["height"] = bb.readVarFloat();
        break;

      case 5:
        result["widthUnit"] = this["ProdAdjustUnitType"][bb.readVarUint()];
        break;

      case 6:
        result["heightUnit"] = this["ProdAdjustUnitType"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdAdjustSize"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["adjustSizeType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ProdAdjustSizeType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdAdjustSizeType\""); bb.writeVarUint(encoded);
  }

  var value = message["baseDirection"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["ProdAdjustBaseType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdAdjustBaseType\""); bb.writeVarUint(encoded);
  }

  var value = message["width"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["height"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["widthUnit"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["ProdAdjustUnitType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdAdjustUnitType\""); bb.writeVarUint(encoded);
  }

  var value = message["heightUnit"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["ProdAdjustUnitType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdAdjustUnitType\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdMoving"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["adjustSizeType"] = this["ProdChangeLocationType"][bb.readVarUint()];
        break;

      case 2:
        result["x"] = bb.readVarFloat();
        break;

      case 3:
        result["y"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdMoving"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["adjustSizeType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ProdChangeLocationType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdChangeLocationType\""); bb.writeVarUint(encoded);
  }

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdRotate"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["rotationType"] = this["ProdRotationType"][bb.readVarUint()];
        break;

      case 2:
        result["anlge"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdRotate"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["rotationType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ProdRotationType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ProdRotationType\""); bb.writeVarUint(encoded);
  }

  var value = message["anlge"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdTableCell"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["cellSizeRow"] = bb.readVarInt();
        break;

      case 2:
        result["cellSizeCol"] = bb.readVarInt();
        break;

      case 3:
        result["mergeToGuid"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["cellHAlign"] = bb.readVarUint();
        break;

      case 5:
        result["cellVAlign"] = bb.readVarUint();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdTableCell"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["cellSizeRow"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["cellSizeCol"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarInt(value);
  }

  var value = message["mergeToGuid"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["cellHAlign"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarUint(value);
  }

  var value = message["cellVAlign"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdTextStyle"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["fontName"] = this["decodeFontName"](bb);
        break;

      case 2:
        result["fillPaint"] = this["decodePaint"](bb);
        break;

      case 3:
        result["fontSize"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdTextStyle"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["fontName"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeFontName"](value, bb);
  }

  var value = message["fillPaint"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodePaint"](value, bb);
  }

  var value = message["fontSize"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdScoreBar"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["numPath"] = bb.readVarInt();
        break;

      case 2:
        result["score"] = bb.readVarFloat();
        break;

      case 3:
        result["scalingFactor"] = this["decodeProdScalingFactor"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdScoreBar"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["numPath"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["score"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["scalingFactor"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeProdScalingFactor"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdDragBar"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["radius"] = bb.readVarFloat();
        break;

      case 2:
        result["scalingFactor"] = this["decodeProdScalingFactor"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdDragBar"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["radius"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["scalingFactor"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeProdScalingFactor"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdScalingFactor"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["wScalingFactor"] = bb.readVarFloat();
        break;

      case 2:
        result["hScalingFactor"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdScalingFactor"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["wScalingFactor"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["hScalingFactor"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdTDCElementinfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["firstVar"] = bb.readString();
        break;

      case 2:
        result["secondVar"] = bb.readString();
        break;

      case 3:
        result["value"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdTDCElementinfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["firstVar"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["secondVar"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeProdTwoDimChart"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["TDCElementInfo"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeProdTDCElementinfo"](bb);
        break;

      case 2:
        result["axisSwitch"] = !!bb.readByte();
        break;

      case 3:
        result["gridSwitch"] = !!bb.readByte();
        break;

      case 4:
        result["titleSwitch"] = !!bb.readByte();
        break;

      case 5:
        result["legendSwitch"] = !!bb.readByte();
        break;

      case 6:
        result["dataLableSwitch"] = !!bb.readByte();
        break;

      case 7:
        result["dataWinSwitch"] = !!bb.readByte();
        break;

      case 8:
        result["legendDir"] = bb.readVarInt();
        break;

      case 9:
        result["colNum"] = bb.readVarInt();
        break;

      case 10:
        result["rowNum"] = bb.readVarInt();
        break;

      case 11:
        result["chartMode"] = bb.readVarInt();
        break;

      case 12:
        var length = bb.readVarUint();
        var values = result["drawArea"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        break;

      case 13:
        var length = bb.readVarUint();
        var values = result["legendSymPos"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        break;

      case 14:
        var length = bb.readVarUint();
        var values = result["axisScale"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeProdTwoDimChart"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["TDCElementInfo"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeProdTDCElementinfo"](value, bb);
    }
  }

  var value = message["axisSwitch"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["gridSwitch"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByte(value);
  }

  var value = message["titleSwitch"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }

  var value = message["legendSwitch"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeByte(value);
  }

  var value = message["dataLableSwitch"];
  if (value != null) {
    bb.writeVarUint(6);
    bb.writeByte(value);
  }

  var value = message["dataWinSwitch"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeByte(value);
  }

  var value = message["legendDir"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeVarInt(value);
  }

  var value = message["colNum"];
  if (value != null) {
    bb.writeVarUint(9);
    bb.writeVarInt(value);
  }

  var value = message["rowNum"];
  if (value != null) {
    bb.writeVarUint(10);
    bb.writeVarInt(value);
  }

  var value = message["chartMode"];
  if (value != null) {
    bb.writeVarUint(11);
    bb.writeVarInt(value);
  }

  var value = message["drawArea"];
  if (value != null) {
    bb.writeVarUint(12);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }

  var value = message["legendSymPos"];
  if (value != null) {
    bb.writeVarUint(13);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }

  var value = message["axisScale"];
  if (value != null) {
    bb.writeVarUint(14);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeGuide"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["axis"] = this["Axis"][bb.readVarUint()];
        break;

      case 2:
        result["offset"] = bb.readVarFloat();
        break;

      case 3:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["distance"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeGuide"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["axis"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["Axis"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Axis\""); bb.writeVarUint(encoded);
  }

  var value = message["offset"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["distance"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeOverlayBackgroundAppearance"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["backgroundType"] = this["OverlayBackgroundType"][bb.readVarUint()];
        break;

      case 2:
        result["backgroundColor"] = this["decodeColor"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeOverlayBackgroundAppearance"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["backgroundType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["OverlayBackgroundType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OverlayBackgroundType\""); bb.writeVarUint(encoded);
  }

  var value = message["backgroundColor"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeColor"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeNumber"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["value"] = bb.readVarFloat();
        break;

      case 2:
        result["units"] = this["NumberUnits"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeNumber"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["units"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["NumberUnits"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NumberUnits\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeParentIndex"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["position"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeParentIndex"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeUserInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["sessionID"] = bb.readVarUint();
        break;

      case 2:
        result["connected"] = !!bb.readByte();
        break;

      case 3:
        result["name"] = bb.readString();
        break;

      case 4:
        result["color"] = this["decodeColor"](bb);
        break;

      case 5:
        result["imageURL"] = bb.readString();
        break;

      case 6:
        result["viewport"] = this["decodeViewport"](bb);
        break;

      case 7:
        result["mouse"] = this["decodeMouse"](bb);
        break;

      case 8:
        var length = bb.readVarUint();
        var values = result["selection"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 9:
        var length = bb.readVarUint();
        var values = result["observing"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        break;

      case 10:
        result["deviceName"] = bb.readString();
        break;

      case 11:
        var length = bb.readVarUint();
        var values = result["recentClicks"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeClick"](bb);
        break;

      case 12:
        var length = bb.readVarUint();
        var values = result["scrollPositions"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeScrollPosition"](bb);
        break;

      case 13:
        result["userID"] = bb.readString();
        break;

      case 14:
        result["lastTriggeredHotspot"] = this["decodeGUID"](bb);
        break;

      case 15:
        result["lastTriggeredPrototypeInteractionID"] = this["decodeGUID"](bb);
        break;

      case 16:
        var length = bb.readVarUint();
        var values = result["triggeredOverlaysData"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeTriggeredOverlayData"](bb);
        break;

      case 17:
        result["spotlight"] = this["decodeSpotlight"](bb);
        break;

      case 18:
        result["lastTriggeredFlowStartPointId"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeUserInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["sessionID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["connected"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeColor"](value, bb);
  }

  var value = message["imageURL"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeString(value);
  }

  var value = message["viewport"];
  if (value != null) {
    bb.writeVarUint(6);
    this["encodeViewport"](value, bb);
  }

  var value = message["mouse"];
  if (value != null) {
    bb.writeVarUint(7);
    this["encodeMouse"](value, bb);
  }

  var value = message["selection"];
  if (value != null) {
    bb.writeVarUint(8);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["observing"];
  if (value != null) {
    bb.writeVarUint(9);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }

  var value = message["deviceName"];
  if (value != null) {
    bb.writeVarUint(10);
    bb.writeString(value);
  }

  var value = message["recentClicks"];
  if (value != null) {
    bb.writeVarUint(11);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeClick"](value, bb);
    }
  }

  var value = message["scrollPositions"];
  if (value != null) {
    bb.writeVarUint(12);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeScrollPosition"](value, bb);
    }
  }

  var value = message["userID"];
  if (value != null) {
    bb.writeVarUint(13);
    bb.writeString(value);
  }

  var value = message["lastTriggeredHotspot"];
  if (value != null) {
    bb.writeVarUint(14);
    this["encodeGUID"](value, bb);
  }

  var value = message["lastTriggeredPrototypeInteractionID"];
  if (value != null) {
    bb.writeVarUint(15);
    this["encodeGUID"](value, bb);
  }

  var value = message["triggeredOverlaysData"];
  if (value != null) {
    bb.writeVarUint(16);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeTriggeredOverlayData"](value, bb);
    }
  }

  var value = message["spotlight"];
  if (value != null) {
    bb.writeVarUint(17);
    this["encodeSpotlight"](value, bb);
  }

  var value = message["lastTriggeredFlowStartPointId"];
  if (value != null) {
    bb.writeVarUint(18);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeViewport"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["canvasSpaceBounds"] = this["decodeRect"](bb);
        break;

      case 2:
        result["pixelPreview"] = !!bb.readByte();
        break;

      case 3:
        result["pixelDensity"] = bb.readVarFloat();
        break;

      case 4:
        result["canvasGuid"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeViewport"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["canvasSpaceBounds"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeRect"](value, bb);
  }

  var value = message["pixelPreview"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["pixelDensity"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["canvasGuid"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeMouse"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["cursor"] = this["MouseCursor"][bb.readVarUint()];
        break;

      case 2:
        result["canvasSpaceLocation"] = this["decodeVector"](bb);
        break;

      case 3:
        result["canvasSpaceSelectionBox"] = this["decodeRect"](bb);
        break;

      case 4:
        result["canvasGuid"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeMouse"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["cursor"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["MouseCursor"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"MouseCursor\""); bb.writeVarUint(encoded);
  }

  var value = message["canvasSpaceLocation"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }

  var value = message["canvasSpaceSelectionBox"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeRect"](value, bb);
  }

  var value = message["canvasGuid"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeClick"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = bb.readVarUint();
        break;

      case 2:
        result["point"] = this["decodeVector"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeClick"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["point"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeScrollPosition"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["node"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["scrollOffset"] = this["decodeVector"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeScrollPosition"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["node"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["scrollOffset"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTriggeredOverlayData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["overlayGuid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["hotspotGuid"] = this["decodeGUID"](bb);
        break;

      case 3:
        result["swapGuid"] = this["decodeGUID"](bb);
        break;

      case 4:
        result["prototypeInteractionGuid"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTriggeredOverlayData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["overlayGuid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["hotspotGuid"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }

  var value = message["swapGuid"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }

  var value = message["prototypeInteractionGuid"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeHyperlink"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["url"] = bb.readString();
        break;

      case 2:
        result["guid"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeHyperlink"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["url"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSharedStyleMasterData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["styleKey"] = bb.readString();
        break;

      case 2:
        result["sortPosition"] = bb.readString();
        break;

      case 3:
        result["fileKey"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSharedStyleMasterData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["styleKey"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["sortPosition"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["fileKey"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSharedStyleReference"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["styleKey"] = bb.readString();
        break;

      case 2:
        result["versionHash"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSharedStyleReference"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["styleKey"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["versionHash"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePixsoMsg"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["PixsoMsgType"][bb.readVarUint()];
        break;

      case 2:
        result["sessionID"] = bb.readVarInt();
        break;

      case 3:
        var length = bb.readVarUint();
        var values = result["pixsoNodes"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePixsoNode"](bb);
        break;

      case 4:
        var length = bb.readVarUint();
        var values = result["blobs"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeBlob"](bb);
        break;

      case 5:
        result["ackID"] = bb.readVarInt();
        break;

      case 6:
        var length = bb.readVarUint();
        var values = result["userInfos"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeUserInfo"](bb);
        break;

      case 7:
        result["access"] = this["Access"][bb.readVarUint()];
        break;

      case 8:
        result["fileVersion"] = bb.readVarUint();
        break;

      case 9:
        result["styleSetName"] = bb.readString();
        break;

      case 10:
        result["styleSetType"] = this["StyleSetType"][bb.readVarUint()];
        break;

      case 11:
        result["styleSetContentType"] = this["StyleSetContentType"][bb.readVarUint()];
        break;

      case 12:
        result["pastePageId"] = this["decodeGUID"](bb);
        break;

      case 13:
        var length = bb.readVarUint();
        var values = result["sceneGraphQueries"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeSceneGraphQuery"](bb);
        break;

      case 14:
        result["signalName"] = bb.readString();
        break;

      case 15:
        result["signalPayload"] = bb.readString();
        break;

      case 16:
        result["createVersion"] = bb.readString();
        break;

      case 17:
        result["lastOpenVersion"] = bb.readString();
        break;

      case 18:
        result["cmdNum"] = this["decodeCommandNum"](bb);
        break;

      case 19:
        result["fileMeta"] = this["decodeFileMeta"](bb);
        break;

      case 20:
        result["pasteFileKey"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePixsoMsg"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["PixsoMsgType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"PixsoMsgType\""); bb.writeVarUint(encoded);
  }

  var value = message["sessionID"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarInt(value);
  }

  var value = message["pixsoNodes"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePixsoNode"](value, bb);
    }
  }

  var value = message["blobs"];
  if (value != null) {
    bb.writeVarUint(4);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeBlob"](value, bb);
    }
  }

  var value = message["ackID"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarInt(value);
  }

  var value = message["userInfos"];
  if (value != null) {
    bb.writeVarUint(6);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeUserInfo"](value, bb);
    }
  }

  var value = message["access"];
  if (value != null) {
    bb.writeVarUint(7);
    var encoded = this["Access"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Access\""); bb.writeVarUint(encoded);
  }

  var value = message["fileVersion"];
  if (value != null) {
    bb.writeVarUint(8);
    bb.writeVarUint(value);
  }

  var value = message["styleSetName"];
  if (value != null) {
    bb.writeVarUint(9);
    bb.writeString(value);
  }

  var value = message["styleSetType"];
  if (value != null) {
    bb.writeVarUint(10);
    var encoded = this["StyleSetType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StyleSetType\""); bb.writeVarUint(encoded);
  }

  var value = message["styleSetContentType"];
  if (value != null) {
    bb.writeVarUint(11);
    var encoded = this["StyleSetContentType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StyleSetContentType\""); bb.writeVarUint(encoded);
  }

  var value = message["pastePageId"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeGUID"](value, bb);
  }

  var value = message["sceneGraphQueries"];
  if (value != null) {
    bb.writeVarUint(13);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeSceneGraphQuery"](value, bb);
    }
  }

  var value = message["signalName"];
  if (value != null) {
    bb.writeVarUint(14);
    bb.writeString(value);
  }

  var value = message["signalPayload"];
  if (value != null) {
    bb.writeVarUint(15);
    bb.writeString(value);
  }

  var value = message["createVersion"];
  if (value != null) {
    bb.writeVarUint(16);
    bb.writeString(value);
  }

  var value = message["lastOpenVersion"];
  if (value != null) {
    bb.writeVarUint(17);
    bb.writeString(value);
  }

  var value = message["cmdNum"];
  if (value != null) {
    bb.writeVarUint(18);
    this["encodeCommandNum"](value, bb);
  }

  var value = message["fileMeta"];
  if (value != null) {
    bb.writeVarUint(19);
    this["encodeFileMeta"](value, bb);
  }

  var value = message["pasteFileKey"];
  if (value != null) {
    bb.writeVarUint(20);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVectorStyleData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["styleID"] = bb.readVarInt();
        break;

      case 2:
        result["cornerRadius"] = bb.readVarFloat();
        break;

      case 3:
        result["strokeCap"] = this["StrokeCap"][bb.readVarUint()];
        break;

      case 4:
        result["strokeJoin"] = this["StrokeJoin"][bb.readVarUint()];
        break;

      case 5:
        result["handleMirroring"] = this["VectorMirror"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVectorStyleData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["styleID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["cornerRadius"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["strokeCap"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["StrokeCap"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeCap\""); bb.writeVarUint(encoded);
  }

  var value = message["strokeJoin"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["StrokeJoin"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"StrokeJoin\""); bb.writeVarUint(encoded);
  }

  var value = message["handleMirroring"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["VectorMirror"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VectorMirror\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTextStyleData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["styleID"] = bb.readVarInt();
        break;

      case 2:
        result["fontSize"] = bb.readVarFloat();
        break;

      case 3:
        result["paragraphIndent"] = bb.readVarFloat();
        break;

      case 4:
        result["paragraphSpacing"] = bb.readVarFloat();
        break;

      case 5:
        result["letterSpacing"] = this["decodeNumber"](bb);
        break;

      case 6:
        result["lineHeight"] = this["decodeNumber"](bb);
        break;

      case 7:
        result["textCase"] = this["TextCase"][bb.readVarUint()];
        break;

      case 8:
        result["textDecoration"] = this["TextDecoration"][bb.readVarUint()];
        break;

      case 9:
        result["textAlignHorizontal"] = this["TextAlignHorizontal"][bb.readVarUint()];
        break;

      case 10:
        result["textAlignVertical"] = this["TextAlignVertical"][bb.readVarUint()];
        break;

      case 11:
        result["textAutoResize"] = this["TextAutoResize"][bb.readVarUint()];
        break;

      case 12:
        result["fontName"] = this["decodeFontName"](bb);
        break;

      case 13:
        result["hyperlink"] = this["decodeHyperlink"](bb);
        break;

      case 14:
        var length = bb.readVarUint();
        var values = result["fillPaints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePaint"](bb);
        break;

      case 15:
        result["inheritFillStyleID"] = this["decodeGUID"](bb);
        break;

      case 16:
        result["inheritTextStyleID"] = this["decodeGUID"](bb);
        break;

      case 17:
        result["fontVariantNumericFigure"] = this["FontVariantNumericFigure"][bb.readVarUint()];
        break;

      case 18:
        result["fontVariantNumericSpacing"] = this["FontVariantNumericSpacing"][bb.readVarUint()];
        break;

      case 19:
        result["fontVariantNumericFraction"] = this["FontVariantNumericFraction"][bb.readVarUint()];
        break;

      case 20:
        result["fontVariantPosition"] = this["FontVariantPosition"][bb.readVarUint()];
        break;

      case 21:
        var length = bb.readVarUint();
        var values = result["toggledOnOTFeatures"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["OpenTypeFeature"][bb.readVarUint()];
        break;

      case 22:
        var length = bb.readVarUint();
        var values = result["toggledOffOTFeatures"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["OpenTypeFeature"][bb.readVarUint()];
        break;

      case 23:
        var length = bb.readVarUint();
        var values = result["fontVariations"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeFontVariation"](bb);
        break;

      case 24:
        result["detachOpticalSizeFromFontSize"] = !!bb.readByte();
        break;

      case 25:
        result["variableConsumptionMap"] = this["decodeVariableDataMap"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTextStyleData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["styleID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["fontSize"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["paragraphIndent"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["paragraphSpacing"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["letterSpacing"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeNumber"](value, bb);
  }

  var value = message["lineHeight"];
  if (value != null) {
    bb.writeVarUint(6);
    this["encodeNumber"](value, bb);
  }

  var value = message["textCase"];
  if (value != null) {
    bb.writeVarUint(7);
    var encoded = this["TextCase"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextCase\""); bb.writeVarUint(encoded);
  }

  var value = message["textDecoration"];
  if (value != null) {
    bb.writeVarUint(8);
    var encoded = this["TextDecoration"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextDecoration\""); bb.writeVarUint(encoded);
  }

  var value = message["textAlignHorizontal"];
  if (value != null) {
    bb.writeVarUint(9);
    var encoded = this["TextAlignHorizontal"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAlignHorizontal\""); bb.writeVarUint(encoded);
  }

  var value = message["textAlignVertical"];
  if (value != null) {
    bb.writeVarUint(10);
    var encoded = this["TextAlignVertical"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAlignVertical\""); bb.writeVarUint(encoded);
  }

  var value = message["textAutoResize"];
  if (value != null) {
    bb.writeVarUint(11);
    var encoded = this["TextAutoResize"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TextAutoResize\""); bb.writeVarUint(encoded);
  }

  var value = message["fontName"];
  if (value != null) {
    bb.writeVarUint(12);
    this["encodeFontName"](value, bb);
  }

  var value = message["hyperlink"];
  if (value != null) {
    bb.writeVarUint(13);
    this["encodeHyperlink"](value, bb);
  }

  var value = message["fillPaints"];
  if (value != null) {
    bb.writeVarUint(14);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePaint"](value, bb);
    }
  }

  var value = message["inheritFillStyleID"];
  if (value != null) {
    bb.writeVarUint(15);
    this["encodeGUID"](value, bb);
  }

  var value = message["inheritTextStyleID"];
  if (value != null) {
    bb.writeVarUint(16);
    this["encodeGUID"](value, bb);
  }

  var value = message["fontVariantNumericFigure"];
  if (value != null) {
    bb.writeVarUint(17);
    var encoded = this["FontVariantNumericFigure"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericFigure\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantNumericSpacing"];
  if (value != null) {
    bb.writeVarUint(18);
    var encoded = this["FontVariantNumericSpacing"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericSpacing\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantNumericFraction"];
  if (value != null) {
    bb.writeVarUint(19);
    var encoded = this["FontVariantNumericFraction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantNumericFraction\""); bb.writeVarUint(encoded);
  }

  var value = message["fontVariantPosition"];
  if (value != null) {
    bb.writeVarUint(20);
    var encoded = this["FontVariantPosition"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontVariantPosition\""); bb.writeVarUint(encoded);
  }

  var value = message["toggledOnOTFeatures"];
  if (value != null) {
    bb.writeVarUint(21);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["OpenTypeFeature"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OpenTypeFeature\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["toggledOffOTFeatures"];
  if (value != null) {
    bb.writeVarUint(22);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["OpenTypeFeature"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"OpenTypeFeature\""); bb.writeVarUint(encoded);
    }
  }

  var value = message["fontVariations"];
  if (value != null) {
    bb.writeVarUint(23);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeFontVariation"](value, bb);
    }
  }

  var value = message["detachOpticalSizeFromFontSize"];
  if (value != null) {
    bb.writeVarUint(24);
    bb.writeByte(value);
  }

  var value = message["variableConsumptionMap"];
  if (value != null) {
    bb.writeVarUint(25);
    this["encodeVariableDataMap"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePropValueData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["property"] = bb.readString();
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["values"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readString();
        break;

      case 3:
        result["aliasProperty"] = bb.readString();
        break;

      case 4:
        var length = bb.readVarUint();
        var values = result["aliasValues"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePropValueData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["property"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["values"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  }

  var value = message["aliasProperty"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["aliasValues"];
  if (value != null) {
    bb.writeVarUint(4);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSceneGraphQuery"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["depth"] = bb.readVarInt();
        break;

      case 2:
        result["startingNode"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSceneGraphQuery"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["depth"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["startingNode"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeStartPoint"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["description"] = bb.readString();
        break;

      case 2:
        result["name"] = bb.readString();
        break;

      case 3:
        result["position"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeStartPoint"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["description"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeConnectLineInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["connlineType"] = this["ConnectLineType"][bb.readVarUint()];
        break;

      case 2:
        result["isFree"] = !!bb.readByte();
        break;

      case 3:
        var length = bb.readVarUint();
        var values = result["connlineSnapObj"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeGUID"](bb);
        break;

      case 4:
        result["textAngleType"] = this["ConnLineTextAngleType"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeConnectLineInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["connlineType"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ConnectLineType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConnectLineType\""); bb.writeVarUint(encoded);
  }

  var value = message["isFree"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["connlineSnapObj"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeGUID"](value, bb);
    }
  }

  var value = message["textAngleType"];
  if (value != null) {
    bb.writeVarUint(4);
    var encoded = this["ConnLineTextAngleType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConnLineTextAngleType\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeObjSnapConnline"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["connectPointType"] = this["ConnectPointType"][bb.readVarUint()];
        break;

      case 3:
        result["snapToObjType"] = this["SnapToObjType"][bb.readVarUint()];
        break;

      case 4:
        result["rate"] = this["decodeVector"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeObjSnapConnline"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["connectPointType"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["ConnectPointType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ConnectPointType\""); bb.writeVarUint(encoded);
  }

  var value = message["snapToObjType"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["SnapToObjType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"SnapToObjType\""); bb.writeVarUint(encoded);
  }

  var value = message["rate"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeVector"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeConnlineTextInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["textGuid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["rate"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeConnlineTextInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["textGuid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["rate"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVectorPaint"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["regionId"] = bb.readVarInt();
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["paints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodePaint"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVectorPaint"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["regionId"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["paints"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodePaint"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVectorStyle"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["regionId"] = bb.readVarInt();
        break;

      case 2:
        result["id"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVectorStyle"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["regionId"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePluginData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["pluginID"] = bb.readString();
        break;

      case 2:
        result["value"] = bb.readString();
        break;

      case 3:
        result["key"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePluginData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["pluginID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePluginRelaunchData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["pluginID"] = bb.readString();
        break;

      case 2:
        result["message"] = bb.readString();
        break;

      case 3:
        result["command"] = bb.readString();
        break;

      case 4:
        result["isDeleted"] = !!bb.readByte();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePluginRelaunchData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["pluginID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["message"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["command"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["isDeleted"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePlaceHolder"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["emojiCodePoints"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
        break;

      case 2:
        result["bound"] = this["decodeRect"](bb);
        break;

      case 3:
        result["firstCharacter"] = bb.readVarInt();
        break;

      case 4:
        result["pose"] = this["decodeGlyphPose"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePlaceHolder"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["emojiCodePoints"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  }

  var value = message["bound"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeRect"](value, bb);
  }

  var value = message["firstCharacter"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }

  var value = message["pose"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeGlyphPose"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSpotlight"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["sessionID"] = bb.readVarUint();
        break;

      case 2:
        result["userID"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSpotlight"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["sessionID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["userID"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeFileMeta"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["fileSource"] = this["FileSource"][bb.readVarUint()];
        break;

      case 2:
        result["fontIncorrect"] = this["FontIncorrect"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeFileMeta"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["fileSource"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["FileSource"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FileSource\""); bb.writeVarUint(encoded);
  }

  var value = message["fontIncorrect"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["FontIncorrect"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"FontIncorrect\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeEditInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["userID"] = bb.readString();
        break;

      case 2:
        result["lastEditedAt"] = bb.readVarUint();
        break;

      case 3:
        result["createAt"] = bb.readVarUint();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeEditInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["userID"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["lastEditedAt"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarUint(value);
  }

  var value = message["createAt"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeSymbolLink"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["uri"] = bb.readString();
        break;

      case 2:
        result["displayName"] = bb.readString();
        break;

      case 3:
        result["displayText"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeSymbolLink"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["uri"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["displayName"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["displayText"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeDeveloperRelatedLink"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["linkName"] = bb.readString();
        break;

      case 2:
        result["linkUrl"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeDeveloperRelatedLink"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["linkName"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["linkUrl"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeFontVariation"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["axisTag"] = bb.readVarUint();
        break;

      case 2:
        result["axisName"] = bb.readString();
        break;

      case 3:
        result["value"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeFontVariation"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["axisTag"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["axisName"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePathTextInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["flipGlyphs"] = !!bb.readByte();
        break;

      case 2:
        result["reverse"] = !!bb.readByte();
        break;

      case 3:
        result["hOffset"] = bb.readVarFloat();
        break;

      case 4:
        result["vOffset"] = bb.readVarFloat();
        break;

      case 5:
        result["tValue"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePathTextInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["flipGlyphs"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByte(value);
  }

  var value = message["reverse"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeByte(value);
  }

  var value = message["hOffset"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["vOffset"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarFloat(value);
  }

  var value = message["tValue"];
  if (value != null) {
    bb.writeVarUint(5);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeGlyphPose"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["x"] = bb.readVarFloat();
        break;

      case 2:
        result["y"] = bb.readVarFloat();
        break;

      case 3:
        result["angle"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeGlyphPose"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }

  var value = message["angle"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeRadialRepeatData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["copies"] = bb.readVarInt();
        break;

      case 2:
        result["radius"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeRadialRepeatData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["copies"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }

  var value = message["radius"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTransformModifier"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["TransformModifierType"][bb.readVarUint()];
        break;

      case 2:
        result["offset"] = this["decodeVector"](bb);
        break;

      case 3:
        result["visible"] = !!bb.readByte();
        break;

      case 4:
        result["count"] = bb.readVarUint();
        break;

      case 5:
        result["repeatType"] = this["RepeatType"][bb.readVarUint()];
        break;

      case 6:
        result["axis"] = this["Axis"][bb.readVarUint()];
        break;

      case 7:
        result["unitType"] = this["UnitType"][bb.readVarUint()];
        break;

      case 8:
        result["order"] = this["RepeatOrder"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTransformModifier"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["TransformModifierType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"TransformModifierType\""); bb.writeVarUint(encoded);
  }

  var value = message["offset"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVector"](value, bb);
  }

  var value = message["visible"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeByte(value);
  }

  var value = message["count"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarUint(value);
  }

  var value = message["repeatType"];
  if (value != null) {
    bb.writeVarUint(5);
    var encoded = this["RepeatType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"RepeatType\""); bb.writeVarUint(encoded);
  }

  var value = message["axis"];
  if (value != null) {
    bb.writeVarUint(6);
    var encoded = this["Axis"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Axis\""); bb.writeVarUint(encoded);
  }

  var value = message["unitType"];
  if (value != null) {
    bb.writeVarUint(7);
    var encoded = this["UnitType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"UnitType\""); bb.writeVarUint(encoded);
  }

  var value = message["order"];
  if (value != null) {
    bb.writeVarUint(8);
    var encoded = this["RepeatOrder"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"RepeatOrder\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAssetID"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["assetRef"] = this["decodeAssetRef"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAssetID"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["assetRef"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeAssetRef"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableSetMode"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["name"] = bb.readString();
        break;

      case 3:
        result["sortPosition"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableSetMode"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["sortPosition"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableDataValues"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["entries"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableDataValuesEntry"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableDataValues"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["entries"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableDataValuesEntry"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableDataValuesEntry"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["modeID"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["variableData"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableDataValuesEntry"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["modeID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["variableData"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableDataMap"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["entries"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableDataMapEntry"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableDataMap"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["entries"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableDataMapEntry"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableDataMapEntry"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["nodeField"] = bb.readVarUint();
        break;

      case 2:
        result["variableData"] = this["decodeVariableData"](bb);
        break;

      case 3:
        result["variableField"] = this["VariableField"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableDataMapEntry"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["nodeField"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["variableData"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }

  var value = message["variableField"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["VariableField"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VariableField\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["value"] = this["decodeVariableAnyValue"](bb);
        break;

      case 2:
        result["dataType"] = this["VariableDataType"][bb.readVarUint()];
        break;

      case 3:
        result["resolvedDataType"] = this["VariableResolvedDataType"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeVariableAnyValue"](value, bb);
  }

  var value = message["dataType"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["VariableDataType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VariableDataType\""); bb.writeVarUint(encoded);
  }

  var value = message["resolvedDataType"];
  if (value != null) {
    bb.writeVarUint(3);
    var encoded = this["VariableResolvedDataType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"VariableResolvedDataType\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableAnyValue"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["boolValue"] = !!bb.readByte();
        break;

      case 2:
        result["textValue"] = bb.readString();
        break;

      case 3:
        result["floatValue"] = bb.readVarFloat();
        break;

      case 4:
        result["alias"] = this["decodeAssetID"](bb);
        break;

      case 5:
        result["colorValue"] = this["decodeColor"](bb);
        break;

      case 6:
        result["expressionValue"] = this["decodeExpression"](bb);
        break;

      case 7:
        result["mapValue"] = this["decodeVariableMap"](bb);
        break;

      case 8:
        result["symbolIdValue"] = this["decodeAssetID"](bb);
        break;

      case 9:
        result["fontStyleValue"] = this["decodeVariableFontStyle"](bb);
        break;

      case 10:
        result["textDataValue"] = this["decodeTextData"](bb);
        break;

      case 11:
        result["nodeFieldAliasValue"] = this["decodeNodeFieldAlias"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableAnyValue"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["boolValue"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByte(value);
  }

  var value = message["textValue"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["floatValue"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }

  var value = message["alias"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeAssetID"](value, bb);
  }

  var value = message["colorValue"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeColor"](value, bb);
  }

  var value = message["expressionValue"];
  if (value != null) {
    bb.writeVarUint(6);
    this["encodeExpression"](value, bb);
  }

  var value = message["mapValue"];
  if (value != null) {
    bb.writeVarUint(7);
    this["encodeVariableMap"](value, bb);
  }

  var value = message["symbolIdValue"];
  if (value != null) {
    bb.writeVarUint(8);
    this["encodeAssetID"](value, bb);
  }

  var value = message["fontStyleValue"];
  if (value != null) {
    bb.writeVarUint(9);
    this["encodeVariableFontStyle"](value, bb);
  }

  var value = message["textDataValue"];
  if (value != null) {
    bb.writeVarUint(10);
    this["encodeTextData"](value, bb);
  }

  var value = message["nodeFieldAliasValue"];
  if (value != null) {
    bb.writeVarUint(11);
    this["encodeNodeFieldAlias"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeExpression"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["expressionFunction"] = this["ExpressionFunction"][bb.readVarUint()];
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["expressionArguments"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeExpression"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["expressionFunction"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["ExpressionFunction"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"ExpressionFunction\""); bb.writeVarUint(encoded);
  }

  var value = message["expressionArguments"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableData"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAssetRef"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["key"] = bb.readString();
        break;

      case 2:
        result["version"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAssetRef"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["version"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableFontStyle"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["asString"] = this["decodeVariableData"](bb);
        break;

      case 2:
        result["asFloat"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableFontStyle"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["asString"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeVariableData"](value, bb);
  }

  var value = message["asFloat"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableMap"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["values"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableMapValue"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableMap"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["values"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableMapValue"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeColorStopVar"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["color"] = this["decodeColor"](bb);
        break;

      case 2:
        result["colorVar"] = this["decodeVariableData"](bb);
        break;

      case 3:
        result["position"] = bb.readVarFloat();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeColorStopVar"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeColor"](value, bb);
  }

  var value = message["colorVar"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }

  var value = message["position"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableModeBySetMap"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["entries"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeVariableModeBySetMapEntry"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableModeBySetMap"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["entries"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeVariableModeBySetMapEntry"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableModeBySetMapEntry"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["variableSetID"] = this["decodeAssetID"](bb);
        break;

      case 2:
        result["variableModeID"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableModeBySetMapEntry"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["variableSetID"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeAssetID"](value, bb);
  }

  var value = message["variableModeID"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableMapValue"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["key"] = bb.readString();
        break;

      case 2:
        result["value"] = this["decodeVariableData"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableMapValue"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["key"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableData"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableIdOrVariableOverrideId"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["variableId"] = this["decodeAssetID"](bb);
        break;

      case 2:
        result["variableOverrideId"] = this["decodeVariableOverrideId"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableIdOrVariableOverrideId"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["variableId"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeAssetID"](value, bb);
  }

  var value = message["variableOverrideId"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeVariableOverrideId"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVariableOverrideId"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["guid"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["assetRef"] = this["decodeAssetRef"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeVariableOverrideId"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["guid"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["assetRef"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeAssetRef"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodePrototypeVariableTarget"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeAssetID"](bb);
        break;

      case 2:
        result["nodeFieldAlias"] = this["decodeNodeFieldAlias"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodePrototypeVariableTarget"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeAssetID"](value, bb);
  }

  var value = message["nodeFieldAlias"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeNodeFieldAlias"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTriggeredSetVariableActionData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["nodeForFindingTopmostScreenId"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["targetVariableId"] = bb.readString();
        break;

      case 3:
        result["targetVariableData"] = bb.readString();
        break;

      case 4:
        result["resolvedVariableModes"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTriggeredSetVariableActionData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["nodeForFindingTopmostScreenId"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["targetVariableId"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["targetVariableData"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["resolvedVariableModes"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeTriggeredSetVariableModeActionData"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["nodeForFindingTopmostScreenId"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["targetVariableSetKey"] = bb.readString();
        break;

      case 3:
        result["targetVariableModeId"] = bb.readString();
        break;

      case 4:
        result["targetVariableSetId"] = this["decodeAssetID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeTriggeredSetVariableModeActionData"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["nodeForFindingTopmostScreenId"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["targetVariableSetKey"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }

  var value = message["targetVariableModeId"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }

  var value = message["targetVariableSetId"];
  if (value != null) {
    bb.writeVarUint(4);
    this["encodeAssetID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeNodeFieldAlias"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["stablePathToNode"] = this["decodeGUIDPath"](bb);
        break;

      case 2:
        result["nodeField"] = this["NodeFieldAliasType"][bb.readVarUint()];
        break;

      case 3:
        result["indexOrKey"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeNodeFieldAlias"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["stablePathToNode"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUIDPath"](value, bb);
  }

  var value = message["nodeField"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["NodeFieldAliasType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"NodeFieldAliasType\""); bb.writeVarUint(encoded);
  }

  var value = message["indexOrKey"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeCodeSyntaxMap"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["entries"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeCodeSyntaxMapEntry"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeCodeSyntaxMap"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["entries"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeCodeSyntaxMapEntry"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeCodeSyntaxMapEntry"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["platform"] = this["CodeSyntaxPlatform"][bb.readVarUint()];
        break;

      case 2:
        result["value"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeCodeSyntaxMapEntry"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["platform"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["CodeSyntaxPlatform"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"CodeSyntaxPlatform\""); bb.writeVarUint(encoded);
  }

  var value = message["value"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeDeliverInfo"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["publishedVersion"] = bb.readString();
        break;

      case 2:
        result["currentVersion"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeDeliverInfo"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["publishedVersion"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["currentVersion"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAnnotationProperty"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["type"] = this["AnnotationPropertyType"][bb.readVarUint()];
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAnnotationProperty"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["type"];
  if (value != null) {
    bb.writeVarUint(1);
    var encoded = this["AnnotationPropertyType"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"AnnotationPropertyType\""); bb.writeVarUint(encoded);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAnnotationCategoryCustom"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["color"] = this["decodeColor"](bb);
        break;

      case 2:
        result["label"] = bb.readString();
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAnnotationCategoryCustom"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["color"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeColor"](value, bb);
  }

  var value = message["label"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAnnotationCategory"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["id"] = this["decodeGUID"](bb);
        break;

      case 2:
        result["preset"] = this["AnnotationCategoryPreset"][bb.readVarUint()];
        break;

      case 3:
        result["custom"] = this["decodeAnnotationCategoryCustom"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAnnotationCategory"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["id"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeGUID"](value, bb);
  }

  var value = message["preset"];
  if (value != null) {
    bb.writeVarUint(2);
    var encoded = this["AnnotationCategoryPreset"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"AnnotationCategoryPreset\""); bb.writeVarUint(encoded);
  }

  var value = message["custom"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeAnnotationCategoryCustom"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAnnotationCategories"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        var length = bb.readVarUint();
        var values = result["items"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeAnnotationCategory"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAnnotationCategories"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["items"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeAnnotationCategory"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeAnnotation"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
    switch (bb.readVarUint()) {
      case 0:
        return result;

      case 1:
        result["label"] = bb.readString();
        break;

      case 2:
        var length = bb.readVarUint();
        var values = result["properties"] = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeAnnotationProperty"](bb);
        break;

      case 3:
        result["categoryId"] = this["decodeGUID"](bb);
        break;

      default:
        throw new Error("Attempted to parse invalid message");
    }
  }
};

exports["encodeAnnotation"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["label"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["properties"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeAnnotationProperty"](value, bb);
    }
  }

  var value = message["categoryId"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeGUID"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};
exports["PixsoMsgType"] = {
  "1": "JOIN_START",
  "2": "NODE_CHANGES",
  "3": "USER_CHANGES",
  "4": "JOIN_END",
  "5": "SIGNAL",
  "6": "STYLE",
  "7": "STYLE_SET",
  "8": "JOIN_START_SKIP_RELOAD",
  "9": "NOTIFY_SHOULD_UPGRADE",
  "10": "UPGRADE_DONE",
  "11": "UPGRADE_REFRESH",
  "12": "SCENE_GRAPH_QUERY",
  "13": "SCENE_GRAPH_REPLY",
  "14": "FIC_DOCUMENT",
  "15": "UPDATE_VERSION",
  "16": "PIX_DOCUMENT",
  "17": "SPOTLIGHT_OPEN",
  "18": "SPOTLIGHT_CLOSE",
  "19": "COMPONENT_QUERY",
  "20": "COMPONENT_REPLY",
  "JOIN_START": 1,
  "NODE_CHANGES": 2,
  "USER_CHANGES": 3,
  "JOIN_END": 4,
  "SIGNAL": 5,
  "STYLE": 6,
  "STYLE_SET": 7,
  "JOIN_START_SKIP_RELOAD": 8,
  "NOTIFY_SHOULD_UPGRADE": 9,
  "UPGRADE_DONE": 10,
  "UPGRADE_REFRESH": 11,
  "SCENE_GRAPH_QUERY": 12,
  "SCENE_GRAPH_REPLY": 13,
  "FIC_DOCUMENT": 14,
  "UPDATE_VERSION": 15,
  "PIX_DOCUMENT": 16,
  "SPOTLIGHT_OPEN": 17,
  "SPOTLIGHT_CLOSE": 18,
  "COMPONENT_QUERY": 19,
  "COMPONENT_REPLY": 20
};
exports["NodePhase"] = {
  "0": "MODIFY",
  "1": "CREATED",
  "2": "REMOVED",
  "MODIFY": 0,
  "CREATED": 1,
  "REMOVED": 2
};
exports["NodeType"] = {
  "1": "NONE",
  "2": "DOCUMENT",
  "3": "CANVAS",
  "4": "GROUP",
  "5": "FRAME",
  "6": "BOOLEAN_OPERATION",
  "7": "VECTOR",
  "8": "STAR",
  "9": "LINE",
  "10": "ELLIPSE",
  "11": "RECTANGLE",
  "12": "REGULAR_POLYGON",
  "13": "ROUNDED_RECTANGLE",
  "14": "TEXT",
  "15": "SLICE",
  "16": "SYMBOL",
  "17": "INSTANCE",
  "18": "CONNECTLINE",
  "19": "DIRECTORY",
  "20": "PROD_RECTANGLE",
  "21": "PROD_ELLIPSE",
  "22": "PROD_STAT",
  "23": "PROD_POLYGON",
  "24": "PROD_DROPDOWNBOX",
  "25": "PROD_EMBEDDEDSVGICON",
  "26": "PROD_SIDEMENU",
  "27": "PROD_LISTMENU",
  "28": "PROD_FIRSTNAVIGATIONBAR",
  "29": "PROD_SECONDNAVIGATIONBAR",
  "30": "PROD_LEFTNAVIGATIONBAR",
  "31": "PROD_DOWNNAVIGATIONBAR",
  "32": "PROD_TABLE",
  "33": "PROD_TABLECELL",
  "34": "PROD_NAVIGATIONBARITEM",
  "35": "PROD_LISTOPTION",
  "36": "PROD_LINE",
  "37": "PROD_TEXT",
  "38": "PROD_NAVIGATIONBAROPTION",
  "39": "PROD_MENUOPTION",
  "40": "PROD_RADIOICONNODE",
  "41": "PROD_PLACEHOLDER",
  "42": "PROD_IMAGEPLACEHOLDER",
  "43": "PROD_PRIMARYBUTTON",
  "44": "PROD_BUTTON",
  "45": "PROD_CHECKBOX",
  "46": "PROD_RADIO",
  "47": "PROD_SWITCH",
  "48": "PROD_TEXTALERT",
  "49": "PROD_SEARCHBOX",
  "50": "PROD_INPUTBOX",
  "51": "PROD_PASSWORDINPUTBOX",
  "52": "PROD_ICONLIST",
  "53": "PROD_SWITCHLIST",
  "54": "PROD_TOAST",
  "55": "PROD_ALERT",
  "56": "PROD_INPUTALERT",
  "57": "PROD_BOTTONALERT",
  "58": "PROD_CARD",
  "59": "PROD_LARGECARD",
  "60": "PROD_MASK",
  "61": "PROD_STATESBAR",
  "62": "PROD_TITLESBAR",
  "63": "PROD_IMAGE",
  "64": "PROD_TITLESBAR2",
  "65": "PROD_THREEBUTTONSALERT",
  "66": "PROD_TICKALERT",
  "67": "PROD_INPUTRANGESEARCH",
  "68": "PROD_INPUTDROP",
  "69": "PROD_INPUTDATA",
  "70": "PROD_INPUTMULROW",
  "71": "PROD_INPUTVERIFICATION",
  "72": "PROD_MENUOPTIONECOMPONENT",
  "73": "PROD_SIDENAVIGATBAR",
  "74": "PROD_DATASELECTOR",
  "75": "PROD_PAGERCOMPONENT",
  "76": "PROD_STEPPER",
  "77": "PROD_MAPCOMPONENT",
  "78": "PROD_HISTOGRAM",
  "79": "PROD_PIECHART",
  "80": "PROD_LINECHART",
  "81": "PROD_ICONBUTTON",
  "82": "PROD_MOREBUTTON",
  "83": "PROD_SCOREBAR",
  "84": "PROD_PROCESSBAR",
  "85": "PROD_DRAGBAR",
  "86": "PROD_SVGFRAME",
  "87": "PROD_LARGECARD3",
  "88": "PROD_LARGECARD4",
  "89": "PROD_TOASTLOADING",
  "90": "PROD_SIDENAVIGATBAR2",
  "91": "PROD_PAGERCOMPONENT2",
  "92": "PROD_ITEMTABLE",
  "93": "PROD_LABEL",
  "94": "PROD_TOASTSUCCESSPC",
  "95": "PROD_TOASTDEFEATERPC",
  "96": "PROD_TOASTWARNPC",
  "97": "PROD_TOASTNOTICEPC",
  "98": "PROD_TOASTLOADINGPC",
  "99": "PROD_TOASTSINGLEBUTTONPC",
  "100": "PROD_TOASTDOUBLEBUTTONPC",
  "101": "PROD_TOASTTIPSPC",
  "102": "PROD_PLUSNAVIGATBAR",
  "103": "PROD_STEPPER2",
  "104": "SECTION",
  "105": "PROD_BREADCRUMB",
  "106": "PROD_BREADCRUMBITEM",
  "107": "PROD_IBUTTON",
  "108": "PROD_IPLACEHOLDER",
  "109": "PROD_IMASK",
  "110": "PROD_ISTATUSBAR",
  "111": "PROD_IINPUTBOX",
  "112": "PROD_IRADIOANDCHECKBUTTON",
  "113": "PROD_IRADIOBUTTON",
  "114": "PROD_ISTEPPER",
  "115": "PROD_VIEWPORTTEXT",
  "116": "PROD_RECTBOX",
  "117": "PROD_SELECTBOX",
  "118": "PROD_SELECTOPTION",
  "119": "PROD_SMARTTABLE",
  "120": "PROD_SMARTTABLECELL",
  "121": "PROD_BLOCK",
  "122": "PROD_BLOCKDOCUMENT",
  "123": "PROD_TOPBARPC",
  "124": "PROD_TOPBARITEMPC",
  "125": "PROD_TOPBAROPTIONPC",
  "126": "PROD_TOPBARMD",
  "127": "PROD_DROPDOWNBOXSIMPLE",
  "128": "PROD_SELECTBOXSTYLE1",
  "129": "PROD_LISTOPTIONMENU",
  "130": "PROD_SIDEBARPC",
  "131": "PROD_SIDEBARITEMPC",
  "132": "PROD_SIDEBAROPTIONPC",
  "133": "PROD_IPAGERCOMPONENT",
  "134": "PROD_SIDENBMD",
  "135": "PROD_SIDENBITEMMD",
  "136": "PROD_DOWNNBMD",
  "137": "PROD_DOWNNBITEMMD",
  "138": "PROD_LABELMD",
  "139": "PROD_LABELPC",
  "140": "PROD_LABELITEM",
  "141": "PROD_DYNAMICPANEL",
  "142": "PROD_DYNAMICPANELSTATE",
  "143": "PROD_HOTZONE",
  "144": "PROD_TAG",
  "145": "PROD_TAGITEM",
  "146": "PROD_AVATAR",
  "147": "PROD_HOTZONE_FIX",
  "148": "PROD_LEFTPANELSVGICON",
  "149": "PROD_BUBBLEPANEL",
  "150": "PROD_TWODIMCHART",
  "151": "PATH_TEXT",
  "152": "RADIAL_PATTERN",
  "153": "VARIABLE",
  "154": "VARIABLE_SET",
  "155": "TRANSFORM",
  "156": "PROD_TREE",
  "157": "PROD_TREEOPTION",
  "158": "PROD_BLOCKMARKER",
  "NONE": 1,
  "DOCUMENT": 2,
  "CANVAS": 3,
  "GROUP": 4,
  "FRAME": 5,
  "BOOLEAN_OPERATION": 6,
  "VECTOR": 7,
  "STAR": 8,
  "LINE": 9,
  "ELLIPSE": 10,
  "RECTANGLE": 11,
  "REGULAR_POLYGON": 12,
  "ROUNDED_RECTANGLE": 13,
  "TEXT": 14,
  "SLICE": 15,
  "SYMBOL": 16,
  "INSTANCE": 17,
  "CONNECTLINE": 18,
  "DIRECTORY": 19,
  "PROD_RECTANGLE": 20,
  "PROD_ELLIPSE": 21,
  "PROD_STAT": 22,
  "PROD_POLYGON": 23,
  "PROD_DROPDOWNBOX": 24,
  "PROD_EMBEDDEDSVGICON": 25,
  "PROD_SIDEMENU": 26,
  "PROD_LISTMENU": 27,
  "PROD_FIRSTNAVIGATIONBAR": 28,
  "PROD_SECONDNAVIGATIONBAR": 29,
  "PROD_LEFTNAVIGATIONBAR": 30,
  "PROD_DOWNNAVIGATIONBAR": 31,
  "PROD_TABLE": 32,
  "PROD_TABLECELL": 33,
  "PROD_NAVIGATIONBARITEM": 34,
  "PROD_LISTOPTION": 35,
  "PROD_LINE": 36,
  "PROD_TEXT": 37,
  "PROD_NAVIGATIONBAROPTION": 38,
  "PROD_MENUOPTION": 39,
  "PROD_RADIOICONNODE": 40,
  "PROD_PLACEHOLDER": 41,
  "PROD_IMAGEPLACEHOLDER": 42,
  "PROD_PRIMARYBUTTON": 43,
  "PROD_BUTTON": 44,
  "PROD_CHECKBOX": 45,
  "PROD_RADIO": 46,
  "PROD_SWITCH": 47,
  "PROD_TEXTALERT": 48,
  "PROD_SEARCHBOX": 49,
  "PROD_INPUTBOX": 50,
  "PROD_PASSWORDINPUTBOX": 51,
  "PROD_ICONLIST": 52,
  "PROD_SWITCHLIST": 53,
  "PROD_TOAST": 54,
  "PROD_ALERT": 55,
  "PROD_INPUTALERT": 56,
  "PROD_BOTTONALERT": 57,
  "PROD_CARD": 58,
  "PROD_LARGECARD": 59,
  "PROD_MASK": 60,
  "PROD_STATESBAR": 61,
  "PROD_TITLESBAR": 62,
  "PROD_IMAGE": 63,
  "PROD_TITLESBAR2": 64,
  "PROD_THREEBUTTONSALERT": 65,
  "PROD_TICKALERT": 66,
  "PROD_INPUTRANGESEARCH": 67,
  "PROD_INPUTDROP": 68,
  "PROD_INPUTDATA": 69,
  "PROD_INPUTMULROW": 70,
  "PROD_INPUTVERIFICATION": 71,
  "PROD_MENUOPTIONECOMPONENT": 72,
  "PROD_SIDENAVIGATBAR": 73,
  "PROD_DATASELECTOR": 74,
  "PROD_PAGERCOMPONENT": 75,
  "PROD_STEPPER": 76,
  "PROD_MAPCOMPONENT": 77,
  "PROD_HISTOGRAM": 78,
  "PROD_PIECHART": 79,
  "PROD_LINECHART": 80,
  "PROD_ICONBUTTON": 81,
  "PROD_MOREBUTTON": 82,
  "PROD_SCOREBAR": 83,
  "PROD_PROCESSBAR": 84,
  "PROD_DRAGBAR": 85,
  "PROD_SVGFRAME": 86,
  "PROD_LARGECARD3": 87,
  "PROD_LARGECARD4": 88,
  "PROD_TOASTLOADING": 89,
  "PROD_SIDENAVIGATBAR2": 90,
  "PROD_PAGERCOMPONENT2": 91,
  "PROD_ITEMTABLE": 92,
  "PROD_LABEL": 93,
  "PROD_TOASTSUCCESSPC": 94,
  "PROD_TOASTDEFEATERPC": 95,
  "PROD_TOASTWARNPC": 96,
  "PROD_TOASTNOTICEPC": 97,
  "PROD_TOASTLOADINGPC": 98,
  "PROD_TOASTSINGLEBUTTONPC": 99,
  "PROD_TOASTDOUBLEBUTTONPC": 100,
  "PROD_TOASTTIPSPC": 101,
  "PROD_PLUSNAVIGATBAR": 102,
  "PROD_STEPPER2": 103,
  "SECTION": 104,
  "PROD_BREADCRUMB": 105,
  "PROD_BREADCRUMBITEM": 106,
  "PROD_IBUTTON": 107,
  "PROD_IPLACEHOLDER": 108,
  "PROD_IMASK": 109,
  "PROD_ISTATUSBAR": 110,
  "PROD_IINPUTBOX": 111,
  "PROD_IRADIOANDCHECKBUTTON": 112,
  "PROD_IRADIOBUTTON": 113,
  "PROD_ISTEPPER": 114,
  "PROD_VIEWPORTTEXT": 115,
  "PROD_RECTBOX": 116,
  "PROD_SELECTBOX": 117,
  "PROD_SELECTOPTION": 118,
  "PROD_SMARTTABLE": 119,
  "PROD_SMARTTABLECELL": 120,
  "PROD_BLOCK": 121,
  "PROD_BLOCKDOCUMENT": 122,
  "PROD_TOPBARPC": 123,
  "PROD_TOPBARITEMPC": 124,
  "PROD_TOPBAROPTIONPC": 125,
  "PROD_TOPBARMD": 126,
  "PROD_DROPDOWNBOXSIMPLE": 127,
  "PROD_SELECTBOXSTYLE1": 128,
  "PROD_LISTOPTIONMENU": 129,
  "PROD_SIDEBARPC": 130,
  "PROD_SIDEBARITEMPC": 131,
  "PROD_SIDEBAROPTIONPC": 132,
  "PROD_IPAGERCOMPONENT": 133,
  "PROD_SIDENBMD": 134,
  "PROD_SIDENBITEMMD": 135,
  "PROD_DOWNNBMD": 136,
  "PROD_DOWNNBITEMMD": 137,
  "PROD_LABELMD": 138,
  "PROD_LABELPC": 139,
  "PROD_LABELITEM": 140,
  "PROD_DYNAMICPANEL": 141,
  "PROD_DYNAMICPANELSTATE": 142,
  "PROD_HOTZONE": 143,
  "PROD_TAG": 144,
  "PROD_TAGITEM": 145,
  "PROD_AVATAR": 146,
  "PROD_HOTZONE_FIX": 147,
  "PROD_LEFTPANELSVGICON": 148,
  "PROD_BUBBLEPANEL": 149,
  "PROD_TWODIMCHART": 150,
  "PATH_TEXT": 151,
  "RADIAL_PATTERN": 152,
  "VARIABLE": 153,
  "VARIABLE_SET": 154,
  "TRANSFORM": 155,
  "PROD_TREE": 156,
  "PROD_TREEOPTION": 157,
  "PROD_BLOCKMARKER": 158
};
exports["MarkerSide"] = {
  "0": "BLOCKSIDE",
  "1": "TARGETSIDE",
  "BLOCKSIDE": 0,
  "TARGETSIDE": 1
};
exports["ProdLayoutMode"] = {
  "1": "NONE",
  "2": "LINEAR",
  "NONE": 1,
  "LINEAR": 2
};
exports["ProdLayoutSizeMode"] = {
  "1": "FIXEDNUM",
  "2": "WRAPCONTENT",
  "3": "MATCHPARENT",
  "FIXEDNUM": 1,
  "WRAPCONTENT": 2,
  "MATCHPARENT": 3
};
exports["ProdChangeLocationType"] = {
  "1": "MOVE",
  "2": "MOVETO",
  "MOVE": 1,
  "MOVETO": 2
};
exports["ProdRotationType"] = {
  "1": "ROTATE",
  "2": "ROTATETO",
  "ROTATE": 1,
  "ROTATETO": 2
};
exports["ProdAdjustSizeType"] = {
  "1": "ADJUST",
  "2": "ADJUSTTO",
  "ADJUST": 1,
  "ADJUSTTO": 2
};
exports["ProdAdjustBaseType"] = {
  "1": "LEFTTOP",
  "2": "TOP",
  "3": "RIGHTTOP",
  "4": "LEFT",
  "5": "CENTER",
  "6": "RIGHT",
  "7": "LEFTBOTTOM",
  "8": "BOTTOM",
  "9": "RIGHTBOTTOM",
  "LEFTTOP": 1,
  "TOP": 2,
  "RIGHTTOP": 3,
  "LEFT": 4,
  "CENTER": 5,
  "RIGHT": 6,
  "LEFTBOTTOM": 7,
  "BOTTOM": 8,
  "RIGHTBOTTOM": 9
};
exports["ProdAdjustUnitType"] = {
  "1": "PERCENTAGE",
  "2": "PIXEL",
  "PERCENTAGE": 1,
  "PIXEL": 2
};
exports["ProdViewportOrientation"] = {
  "1": "Horizontal",
  "2": "Vertical",
  "Horizontal": 1,
  "Vertical": 2
};
exports["ProdBlockStyleType"] = {
  "0": "DEFAULT",
  "1": "H1",
  "2": "H2",
  "3": "H3",
  "DEFAULT": 0,
  "H1": 1,
  "H2": 2,
  "H3": 3
};
exports["BooleanOperation"] = {
  "1": "UNION",
  "2": "INTERSECT",
  "3": "SUBTRACT",
  "4": "XOR",
  "UNION": 1,
  "INTERSECT": 2,
  "SUBTRACT": 3,
  "XOR": 4
};
exports["BlendMode"] = {
  "1": "PASS_THROUGH",
  "2": "NORMAL",
  "3": "DARKEN",
  "4": "MULTIPLY",
  "5": "LINEAR_BURN",
  "6": "COLOR_BURN",
  "7": "LIGHTEN",
  "8": "SCREEN",
  "9": "LINEAR_DODGE",
  "10": "COLOR_DODGE",
  "11": "OVERLAY",
  "12": "SOFT_LIGHT",
  "13": "HARD_LIGHT",
  "14": "DIFFERENCE",
  "15": "EXCLUSION",
  "16": "HUE",
  "17": "SATURATION",
  "18": "COLOR",
  "19": "LUMINOSITY",
  "PASS_THROUGH": 1,
  "NORMAL": 2,
  "DARKEN": 3,
  "MULTIPLY": 4,
  "LINEAR_BURN": 5,
  "COLOR_BURN": 6,
  "LIGHTEN": 7,
  "SCREEN": 8,
  "LINEAR_DODGE": 9,
  "COLOR_DODGE": 10,
  "OVERLAY": 11,
  "SOFT_LIGHT": 12,
  "HARD_LIGHT": 13,
  "DIFFERENCE": 14,
  "EXCLUSION": 15,
  "HUE": 16,
  "SATURATION": 17,
  "COLOR": 18,
  "LUMINOSITY": 19
};
exports["NoiseType"] = {
  "0": "MULTITONE",
  "1": "MONOTONE",
  "2": "DUOTONE",
  "MULTITONE": 0,
  "MONOTONE": 1,
  "DUOTONE": 2
};
exports["EffectType"] = {
  "1": "INNER_SHADOW",
  "2": "DROP_SHADOW",
  "3": "FOREGROUND_BLUR",
  "4": "BACKGROUND_BLUR",
  "5": "MOTION_BLUR",
  "6": "GLASS",
  "7": "GRAIN",
  "8": "NOISE",
  "9": "ZOOM_BLUR",
  "INNER_SHADOW": 1,
  "DROP_SHADOW": 2,
  "FOREGROUND_BLUR": 3,
  "BACKGROUND_BLUR": 4,
  "MOTION_BLUR": 5,
  "GLASS": 6,
  "GRAIN": 7,
  "NOISE": 8,
  "ZOOM_BLUR": 9
};
exports["StackCounterAlign"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "MAX",
  "4": "STRETCH",
  "MIN": 1,
  "CENTER": 2,
  "MAX": 3,
  "STRETCH": 4
};
exports["StackAlignItemMode"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "MAX",
  "4": "SPACE_EVENLY",
  "MIN": 1,
  "CENTER": 2,
  "MAX": 3,
  "SPACE_EVENLY": 4
};
exports["StackSize"] = {
  "1": "FIXED",
  "2": "RESIZE_TO_FIT",
  "FIXED": 1,
  "RESIZE_TO_FIT": 2
};
exports["StackJustify"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "MAX",
  "4": "SPACE_EVENLY",
  "MIN": 1,
  "CENTER": 2,
  "MAX": 3,
  "SPACE_EVENLY": 4
};
exports["StackMode"] = {
  "1": "NONE",
  "2": "HORIZONTAL",
  "3": "VERTICAL",
  "4": "GRID",
  "NONE": 1,
  "HORIZONTAL": 2,
  "VERTICAL": 3,
  "GRID": 4
};
exports["StrokeAlign"] = {
  "1": "CENTER",
  "2": "INSIDE",
  "3": "OUTSIDE",
  "CENTER": 1,
  "INSIDE": 2,
  "OUTSIDE": 3
};
exports["StrokeCap"] = {
  "1": "NONE",
  "2": "ROUND",
  "3": "SQUARE",
  "4": "ARROW_LINES",
  "5": "ARROW_EQUILATERAL",
  "6": "TRIANGLE_FILLED",
  "7": "DIAMOND_FILLED",
  "8": "HOLLOW_ROUND",
  "9": "SOLID_ROUND",
  "10": "VERTICAL_LINE",
  "NONE": 1,
  "ROUND": 2,
  "SQUARE": 3,
  "ARROW_LINES": 4,
  "ARROW_EQUILATERAL": 5,
  "TRIANGLE_FILLED": 6,
  "DIAMOND_FILLED": 7,
  "HOLLOW_ROUND": 8,
  "SOLID_ROUND": 9,
  "VERTICAL_LINE": 10
};
exports["StrokeJoin"] = {
  "1": "MITER",
  "2": "BEVEL",
  "3": "ROUND",
  "MITER": 1,
  "BEVEL": 2,
  "ROUND": 3
};
exports["StyleType"] = {
  "1": "NONE",
  "2": "FILL",
  "3": "STROKE",
  "4": "TEXT",
  "5": "EFFECT",
  "6": "EXPORT",
  "7": "GRID",
  "NONE": 1,
  "FILL": 2,
  "STROKE": 3,
  "TEXT": 4,
  "EFFECT": 5,
  "EXPORT": 6,
  "GRID": 7
};
exports["LayoutGridType"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "STRETCH",
  "4": "MAX",
  "MIN": 1,
  "CENTER": 2,
  "STRETCH": 3,
  "MAX": 4
};
exports["Axis"] = {
  "1": "X",
  "2": "Y",
  "X": 1,
  "Y": 2
};
exports["LayoutGridPattern"] = {
  "1": "STRIPES",
  "2": "GRID",
  "STRIPES": 1,
  "GRID": 2
};
exports["GridChildAlign"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "MAX",
  "MIN": 1,
  "CENTER": 2,
  "MAX": 3
};
exports["GridTrackSizingType"] = {
  "1": "FLEX",
  "2": "FIXED",
  "FLEX": 1,
  "FIXED": 2
};
exports["ImageType"] = {
  "1": "PNG",
  "2": "JPEG",
  "3": "SVG",
  "4": "PDF",
  "5": "SKETCH",
  "6": "EPS",
  "7": "TIFF",
  "8": "WEBP",
  "PNG": 1,
  "JPEG": 2,
  "SVG": 3,
  "PDF": 4,
  "SKETCH": 5,
  "EPS": 6,
  "TIFF": 7,
  "WEBP": 8
};
exports["ExportConstraintType"] = {
  "1": "CONTENT_SCALE",
  "2": "CONTENT_WIDTH",
  "3": "CONTENT_HEIGHT",
  "CONTENT_SCALE": 1,
  "CONTENT_WIDTH": 2,
  "CONTENT_HEIGHT": 3
};
exports["ExportSVGIDMode"] = {
  "1": "IF_NEEDED",
  "2": "ALWAYS",
  "IF_NEEDED": 1,
  "ALWAYS": 2
};
exports["FontVariantCaps"] = {
  "1": "NORMAL",
  "2": "SMALL",
  "3": "ALL_SMALL",
  "4": "PETITE",
  "5": "ALL_PETITE",
  "6": "UNICASE",
  "7": "TITLING",
  "NORMAL": 1,
  "SMALL": 2,
  "ALL_SMALL": 3,
  "PETITE": 4,
  "ALL_PETITE": 5,
  "UNICASE": 6,
  "TITLING": 7
};
exports["FontVariantNumericFigure"] = {
  "1": "NORMAL",
  "2": "LINING",
  "3": "OLDSTYLE",
  "NORMAL": 1,
  "LINING": 2,
  "OLDSTYLE": 3
};
exports["FontVariantNumericFraction"] = {
  "1": "NORMAL",
  "2": "DIAGONAL",
  "3": "STACKED",
  "NORMAL": 1,
  "DIAGONAL": 2,
  "STACKED": 3
};
exports["FontVariantNumericSpacing"] = {
  "1": "NORMAL",
  "2": "PROPORTIONAL",
  "3": "TABULAR",
  "NORMAL": 1,
  "PROPORTIONAL": 2,
  "TABULAR": 3
};
exports["FontVariantPosition"] = {
  "1": "NORMAL",
  "2": "SUB",
  "3": "SUPER",
  "NORMAL": 1,
  "SUB": 2,
  "SUPER": 3
};
exports["TextAlignHorizontal"] = {
  "1": "LEFT",
  "2": "CENTER",
  "3": "RIGHT",
  "4": "JUSTIFIED",
  "LEFT": 1,
  "CENTER": 2,
  "RIGHT": 3,
  "JUSTIFIED": 4
};
exports["TextAlignVertical"] = {
  "1": "TOP",
  "2": "CENTER",
  "3": "BOTTOM",
  "TOP": 1,
  "CENTER": 2,
  "BOTTOM": 3
};
exports["TextAutoResize"] = {
  "1": "NONE",
  "2": "WIDTH_AND_HEIGHT",
  "3": "HEIGHT",
  "NONE": 1,
  "WIDTH_AND_HEIGHT": 2,
  "HEIGHT": 3
};
exports["TextCase"] = {
  "1": "ORIGINAL",
  "2": "UPPER",
  "3": "LOWER",
  "4": "TITLE",
  "5": "SMALL_CAPS",
  "6": "SMALL_CAPS_FORCED",
  "ORIGINAL": 1,
  "UPPER": 2,
  "LOWER": 3,
  "TITLE": 4,
  "SMALL_CAPS": 5,
  "SMALL_CAPS_FORCED": 6
};
exports["FontStyle"] = {
  "1": "NORMAL",
  "2": "ITALIC",
  "NORMAL": 1,
  "ITALIC": 2
};
exports["TextDecoration"] = {
  "1": "NONE",
  "2": "UNDERLINE",
  "3": "STRIKETHROUGH",
  "NONE": 1,
  "UNDERLINE": 2,
  "STRIKETHROUGH": 3
};
exports["ConstraintType"] = {
  "1": "MIN",
  "2": "CENTER",
  "3": "MAX",
  "4": "STRETCH",
  "5": "SCALE",
  "6": "FIXED_MIN",
  "7": "FIXED_MAX",
  "MIN": 1,
  "CENTER": 2,
  "MAX": 3,
  "STRETCH": 4,
  "SCALE": 5,
  "FIXED_MIN": 6,
  "FIXED_MAX": 7
};
exports["TriggerDevice"] = {
  "1": "KEYBOARD",
  "2": "UNKNOWN_CONTROLLER",
  "3": "XBOX_ONE",
  "4": "PS4",
  "5": "SWITCH_PRO",
  "KEYBOARD": 1,
  "UNKNOWN_CONTROLLER": 2,
  "XBOX_ONE": 3,
  "PS4": 4,
  "SWITCH_PRO": 5
};
exports["InteractionType"] = {
  "1": "ON_CLICK",
  "2": "AFTER_TIMEOUT",
  "3": "MOUSE_IN",
  "4": "MOUSE_OUT",
  "5": "ON_HOVER",
  "6": "MOUSE_DOWN",
  "7": "MOUSE_UP",
  "8": "ON_PRESS",
  "9": "NONE",
  "10": "DRAG",
  "11": "ON_KEY_DOWN",
  "12": "ON_VOICE",
  "13": "ON_DOUBLECLICK",
  "14": "SIDE_LEFT",
  "15": "SIDE_RIGHT",
  "16": "SIDE_UP",
  "17": "SIDE_DOWN",
  "ON_CLICK": 1,
  "AFTER_TIMEOUT": 2,
  "MOUSE_IN": 3,
  "MOUSE_OUT": 4,
  "ON_HOVER": 5,
  "MOUSE_DOWN": 6,
  "MOUSE_UP": 7,
  "ON_PRESS": 8,
  "NONE": 9,
  "DRAG": 10,
  "ON_KEY_DOWN": 11,
  "ON_VOICE": 12,
  "ON_DOUBLECLICK": 13,
  "SIDE_LEFT": 14,
  "SIDE_RIGHT": 15,
  "SIDE_UP": 16,
  "SIDE_DOWN": 17
};
exports["ConnectionType"] = {
  "1": "NONE",
  "2": "INTERNAL_NODE",
  "3": "URL",
  "4": "BACK",
  "5": "CLOSE",
  "6": "SCROLLTO",
  "7": "SETSHOWHIDE",
  "8": "CHANGESIZE",
  "9": "CHANGELOCATION",
  "10": "CHANGEDYNAMICPANELSTATE",
  "11": "ROTATION",
  "12": "WAIT",
  "13": "UPDATE_MEDIA_RUNTIME",
  "14": "CONDITIONAL",
  "15": "SET_VARIABLE",
  "16": "SET_VARIABLE_MODE",
  "17": "SET_ENABLE_STATE",
  "18": "SET_SELECTED_STATE",
  "19": "SET_SWITCH_STATE",
  "NONE": 1,
  "INTERNAL_NODE": 2,
  "URL": 3,
  "BACK": 4,
  "CLOSE": 5,
  "SCROLLTO": 6,
  "SETSHOWHIDE": 7,
  "CHANGESIZE": 8,
  "CHANGELOCATION": 9,
  "CHANGEDYNAMICPANELSTATE": 10,
  "ROTATION": 11,
  "WAIT": 12,
  "UPDATE_MEDIA_RUNTIME": 13,
  "CONDITIONAL": 14,
  "SET_VARIABLE": 15,
  "SET_VARIABLE_MODE": 16,
  "SET_ENABLE_STATE": 17,
  "SET_SELECTED_STATE": 18,
  "SET_SWITCH_STATE": 19
};
exports["PrototypeStateAction"] = {
  "1": "TRUE_STATE",
  "2": "FALSE_STATE",
  "3": "TOGGLE",
  "TRUE_STATE": 1,
  "FALSE_STATE": 2,
  "TOGGLE": 3
};
exports["PrototypeSelectedStateType"] = {
  "1": "SELECT_GUID",
  "2": "SWITCH_STATUS",
  "3": "CHECKBOX_STATE",
  "SELECT_GUID": 1,
  "SWITCH_STATUS": 2,
  "CHECKBOX_STATE": 3
};
exports["EasingType"] = {
  "1": "LINEAR",
  "2": "IN_CUBIC",
  "3": "OUT_CUBIC",
  "4": "INOUT_CUBIC",
  "5": "INBACK_CUBIC",
  "6": "OUTBACK_CUBIC",
  "7": "INOUTBACK_CUBIC",
  "8": "CUSTOM_CUBIC",
  "9": "NONE",
  "10": "SPRING",
  "11": "GENTLE_SPRING",
  "12": "CUSTOM_SPRING",
  "13": "SPRING_PRESET_ONE",
  "14": "SPRING_PRESET_TWO",
  "15": "SPRING_PRESET_THREE",
  "LINEAR": 1,
  "IN_CUBIC": 2,
  "OUT_CUBIC": 3,
  "INOUT_CUBIC": 4,
  "INBACK_CUBIC": 5,
  "OUTBACK_CUBIC": 6,
  "INOUTBACK_CUBIC": 7,
  "CUSTOM_CUBIC": 8,
  "NONE": 9,
  "SPRING": 10,
  "GENTLE_SPRING": 11,
  "CUSTOM_SPRING": 12,
  "SPRING_PRESET_ONE": 13,
  "SPRING_PRESET_TWO": 14,
  "SPRING_PRESET_THREE": 15
};
exports["PrototypeDeviceType"] = {
  "1": "NONE",
  "2": "PRESET",
  "3": "CUSTOM",
  "4": "PRESENTATION",
  "NONE": 1,
  "PRESET": 2,
  "CUSTOM": 3,
  "PRESENTATION": 4
};
exports["PrototypeShowHide"] = {
  "1": "SHOW",
  "2": "HIDE",
  "3": "SWITCH",
  "SHOW": 1,
  "HIDE": 2,
  "SWITCH": 3
};
exports["DeviceRotation"] = {
  "1": "NONE",
  "2": "CCW_90",
  "NONE": 1,
  "CCW_90": 2
};
exports["TransitionType"] = {
  "1": "INSTANT_TRANSITION",
  "2": "DISSOLVE",
  "3": "SMART_ANIMATE",
  "4": "SLIDE_FROM_LEFT",
  "5": "SLIDE_FROM_RIGHT",
  "6": "SLIDE_FROM_TOP",
  "7": "SLIDE_FROM_BOTTOM",
  "8": "PUSH_FROM_LEFT",
  "9": "PUSH_FROM_RIGHT",
  "10": "PUSH_FROM_TOP",
  "11": "PUSH_FROM_BOTTOM",
  "12": "MOVE_FROM_LEFT",
  "13": "MOVE_FROM_RIGHT",
  "14": "MOVE_FROM_TOP",
  "15": "MOVE_FROM_BOTTOM",
  "16": "SLIDE_OUT_TO_LEFT",
  "17": "SLIDE_OUT_TO_RIGHT",
  "18": "SLIDE_OUT_TO_TOP",
  "19": "SLIDE_OUT_TO_BOTTOM",
  "20": "MOVE_OUT_TO_LEFT",
  "21": "MOVE_OUT_TO_RIGHT",
  "22": "MOVE_OUT_TO_TOP",
  "23": "MOVE_OUT_TO_BOTTOM",
  "24": "MAGIC_MOVE",
  "25": "SCROLL_ANIMATE",
  "26": "LAYER_DISSOLVE",
  "INSTANT_TRANSITION": 1,
  "DISSOLVE": 2,
  "SMART_ANIMATE": 3,
  "SLIDE_FROM_LEFT": 4,
  "SLIDE_FROM_RIGHT": 5,
  "SLIDE_FROM_TOP": 6,
  "SLIDE_FROM_BOTTOM": 7,
  "PUSH_FROM_LEFT": 8,
  "PUSH_FROM_RIGHT": 9,
  "PUSH_FROM_TOP": 10,
  "PUSH_FROM_BOTTOM": 11,
  "MOVE_FROM_LEFT": 12,
  "MOVE_FROM_RIGHT": 13,
  "MOVE_FROM_TOP": 14,
  "MOVE_FROM_BOTTOM": 15,
  "SLIDE_OUT_TO_LEFT": 16,
  "SLIDE_OUT_TO_RIGHT": 17,
  "SLIDE_OUT_TO_TOP": 18,
  "SLIDE_OUT_TO_BOTTOM": 19,
  "MOVE_OUT_TO_LEFT": 20,
  "MOVE_OUT_TO_RIGHT": 21,
  "MOVE_OUT_TO_TOP": 22,
  "MOVE_OUT_TO_BOTTOM": 23,
  "MAGIC_MOVE": 24,
  "SCROLL_ANIMATE": 25,
  "LAYER_DISSOLVE": 26
};
exports["OverlayBackgroundInteraction"] = {
  "1": "NONE",
  "2": "CLOSE_ON_CLICK_OUTSIDE",
  "NONE": 1,
  "CLOSE_ON_CLICK_OUTSIDE": 2
};
exports["OverlayBackgroundType"] = {
  "1": "NONE",
  "2": "SOLID_COLOR",
  "NONE": 1,
  "SOLID_COLOR": 2
};
exports["OverlayPositionType"] = {
  "1": "CENTER",
  "2": "TOP_LEFT",
  "3": "TOP_CENTER",
  "4": "TOP_RIGHT",
  "5": "BOTTOM_LEFT",
  "6": "BOTTOM_CENTER",
  "7": "BOTTOM_RIGHT",
  "8": "MANUAL",
  "CENTER": 1,
  "TOP_LEFT": 2,
  "TOP_CENTER": 3,
  "TOP_RIGHT": 4,
  "BOTTOM_LEFT": 5,
  "BOTTOM_CENTER": 6,
  "BOTTOM_RIGHT": 7,
  "MANUAL": 8
};
exports["ScrollDirection"] = {
  "1": "NONE",
  "2": "HORIZONTAL",
  "3": "VERTICAL",
  "4": "BOTH",
  "NONE": 1,
  "HORIZONTAL": 2,
  "VERTICAL": 3,
  "BOTH": 4
};
exports["NavigationType"] = {
  "1": "NAVIGATE",
  "2": "OVERLAY",
  "3": "SWAP",
  "4": "SWAP_STATE",
  "5": "SCROLL_TO",
  "6": "SHOW_HIDE",
  "NAVIGATE": 1,
  "OVERLAY": 2,
  "SWAP": 3,
  "SWAP_STATE": 4,
  "SCROLL_TO": 5,
  "SHOW_HIDE": 6
};
exports["MediaAction"] = {
  "1": "PLAY",
  "2": "PAUSE",
  "3": "TOGGLE_PLAY_PAUSE",
  "4": "MUTE",
  "5": "UNMUTE",
  "6": "TOGGLE_MUTE_UNMUTE",
  "7": "SKIP_FORWARD",
  "8": "SKIP_BACKWARD",
  "9": "SKIP_TO",
  "PLAY": 1,
  "PAUSE": 2,
  "TOGGLE_PLAY_PAUSE": 3,
  "MUTE": 4,
  "UNMUTE": 5,
  "TOGGLE_MUTE_UNMUTE": 6,
  "SKIP_FORWARD": 7,
  "SKIP_BACKWARD": 8,
  "SKIP_TO": 9
};
exports["NumberUnits"] = {
  "1": "RAW",
  "2": "PIXELS",
  "3": "PERCENT",
  "RAW": 1,
  "PIXELS": 2,
  "PERCENT": 3
};
exports["ScrollBehavior"] = {
  "1": "SCROLLS",
  "2": "FIXED_WHEN_CHILD_OF_SCROLLING_FRAME",
  "SCROLLS": 1,
  "FIXED_WHEN_CHILD_OF_SCROLLING_FRAME": 2
};
exports["PatternAlignment"] = {
  "0": "START",
  "1": "CENTER",
  "2": "END",
  "START": 0,
  "CENTER": 1,
  "END": 2
};
exports["PatternTileType"] = {
  "0": "RECTANGULAR",
  "1": "HORIZONTAL_HEXAGONAL",
  "2": "VERTICAL_HEXAGONAL",
  "RECTANGULAR": 0,
  "HORIZONTAL_HEXAGONAL": 1,
  "VERTICAL_HEXAGONAL": 2
};
exports["PaintType"] = {
  "1": "SOLID",
  "2": "GRADIENT_LINEAR",
  "3": "GRADIENT_RADIAL",
  "4": "GRADIENT_ANGULAR",
  "5": "GRADIENT_DIAMOND",
  "6": "IMAGE",
  "7": "EMOJI",
  "8": "GIF",
  "9": "VIDEO",
  "10": "PATTERN",
  "SOLID": 1,
  "GRADIENT_LINEAR": 2,
  "GRADIENT_RADIAL": 3,
  "GRADIENT_ANGULAR": 4,
  "GRADIENT_DIAMOND": 5,
  "IMAGE": 6,
  "EMOJI": 7,
  "GIF": 8,
  "VIDEO": 9,
  "PATTERN": 10
};
exports["ImageScaleMode"] = {
  "1": "STRETCH",
  "2": "FIT",
  "3": "FILL",
  "4": "TILE",
  "STRETCH": 1,
  "FIT": 2,
  "FILL": 3,
  "TILE": 4
};
exports["ScrollBar"] = {
  "1": "AUTOSHOW",
  "2": "SHOW",
  "3": "HIDE",
  "AUTOSHOW": 1,
  "SHOW": 2,
  "HIDE": 3
};
exports["ComponentStateType"] = {
  "0": "DEFAULT_STATE",
  "1": "HOVER_STATE",
  "2": "ACTIVE_STATE",
  "3": "DISABLED_STATE",
  "DEFAULT_STATE": 0,
  "HOVER_STATE": 1,
  "ACTIVE_STATE": 2,
  "DISABLED_STATE": 3
};
exports["MouseCursor"] = {
  "1": "DEFAULT",
  "2": "CROSSHAIR",
  "3": "EYEDROPPER",
  "4": "HAND",
  "5": "PAINT_BUCKET",
  "6": "PEN",
  "7": "PENCIL",
  "DEFAULT": 1,
  "CROSSHAIR": 2,
  "EYEDROPPER": 3,
  "HAND": 4,
  "PAINT_BUCKET": 5,
  "PEN": 6,
  "PENCIL": 7
};
exports["Access"] = {
  "1": "READ_ONLY",
  "2": "READ_WRITE",
  "READ_ONLY": 1,
  "READ_WRITE": 2
};
exports["StyleSetType"] = {
  "1": "PERSONAL",
  "2": "TEAM",
  "3": "CUSTOM",
  "4": "FREQUENCY",
  "5": "TEMPORARY",
  "PERSONAL": 1,
  "TEAM": 2,
  "CUSTOM": 3,
  "FREQUENCY": 4,
  "TEMPORARY": 5
};
exports["StyleSetContentType"] = {
  "1": "SOLID",
  "2": "GRADIENT",
  "3": "IMAGE",
  "SOLID": 1,
  "GRADIENT": 2,
  "IMAGE": 3
};
exports["WindingRule"] = {
  "1": "NONZERO",
  "2": "ODD",
  "3": "INVERSE_NONZERO",
  "4": "INVERSE_ODD",
  "NONZERO": 1,
  "ODD": 2,
  "INVERSE_NONZERO": 3,
  "INVERSE_ODD": 4
};
exports["VectorMirror"] = {
  "1": "NONE",
  "2": "ANGLE",
  "3": "ANGLE_AND_LENGTH",
  "4": "RIGHT_ANGLE",
  "NONE": 1,
  "ANGLE": 2,
  "ANGLE_AND_LENGTH": 3,
  "RIGHT_ANGLE": 4
};
exports["OverflowType"] = {
  "1": "NONE",
  "2": "HORIZONTAL",
  "3": "VERTICAL",
  "4": "HORIZONTAL_AND_VERTICAL",
  "NONE": 1,
  "HORIZONTAL": 2,
  "VERTICAL": 3,
  "HORIZONTAL_AND_VERTICAL": 4
};
exports["ConnectLineType"] = {
  "1": "StraightLine",
  "2": "Curve",
  "3": "RightAngle",
  "4": "FilletPlotLine",
  "StraightLine": 1,
  "Curve": 2,
  "RightAngle": 3,
  "FilletPlotLine": 4
};
exports["ConnLineTextAngleType"] = {
  "1": "Horizontal",
  "2": "TangentAngle",
  "Horizontal": 1,
  "TangentAngle": 2
};
exports["ConnectPointType"] = {
  "1": "None",
  "2": "BeginPt",
  "3": "EndPt",
  "None": 1,
  "BeginPt": 2,
  "EndPt": 3
};
exports["SnapToObjType"] = {
  "1": "None",
  "2": "CenterPt",
  "3": "Outline",
  "4": "Vertex",
  "5": "Inside",
  "6": "WholeShape",
  "None": 1,
  "CenterPt": 2,
  "Outline": 3,
  "Vertex": 4,
  "Inside": 5,
  "WholeShape": 6
};
exports["ExportImageQualityOp"] = {
  "1": "ExportQuality_Origin",
  "2": "ExportQuality_High",
  "3": "ExportQuality_Mid",
  "4": "ExportQuality_Low",
  "ExportQuality_Origin": 1,
  "ExportQuality_High": 2,
  "ExportQuality_Mid": 3,
  "ExportQuality_Low": 4
};
exports["TextListStyle"] = {
  "0": "PLAIN",
  "1": "ORDERED_LIST",
  "2": "UNORDERED_LIST",
  "PLAIN": 0,
  "ORDERED_LIST": 1,
  "UNORDERED_LIST": 2
};
exports["TextTruncation"] = {
  "0": "DISABLED",
  "1": "ENDING",
  "DISABLED": 0,
  "ENDING": 1
};
exports["MaskType"] = {
  "0": "ALPHA",
  "1": "OUTLINE",
  "2": "LUMINANCE",
  "ALPHA": 0,
  "OUTLINE": 1,
  "LUMINANCE": 2
};
exports["LeadingTrim"] = {
  "0": "NONE",
  "1": "CAP_HEIGHT",
  "NONE": 0,
  "CAP_HEIGHT": 1
};
exports["OpenTypeFeature"] = {
  "0": "PCAP",
  "1": "C2PC",
  "2": "CASE",
  "3": "CPSP",
  "4": "TITL",
  "5": "UNIC",
  "6": "ZERO",
  "7": "SINF",
  "8": "ORDN",
  "9": "AFRC",
  "10": "DNOM",
  "11": "NUMR",
  "12": "LIGA",
  "13": "CLIG",
  "14": "DLIG",
  "15": "HLIG",
  "16": "RLIG",
  "17": "AALT",
  "18": "CALT",
  "19": "RCLT",
  "20": "SALT",
  "21": "RVRN",
  "22": "VERT",
  "23": "SWSH",
  "24": "CSWH",
  "25": "NALT",
  "26": "CCMP",
  "27": "STCH",
  "28": "HIST",
  "29": "SIZE",
  "30": "ORNM",
  "31": "ITAL",
  "32": "RAND",
  "33": "DTLS",
  "34": "FLAC",
  "35": "MGRK",
  "36": "SSTY",
  "37": "KERN",
  "38": "FWID",
  "39": "HWID",
  "40": "HALT",
  "41": "TWID",
  "42": "QWID",
  "43": "PWID",
  "44": "JUST",
  "45": "LFBD",
  "46": "OPBD",
  "47": "RTBD",
  "48": "PALT",
  "49": "PKNA",
  "50": "LTRA",
  "51": "LTRM",
  "52": "RTLA",
  "53": "RTLM",
  "54": "ABRV",
  "55": "ABVM",
  "56": "ABVS",
  "57": "VALT",
  "58": "VHAL",
  "59": "BLWF",
  "60": "BLWM",
  "61": "BLWS",
  "62": "AKHN",
  "63": "CJCT",
  "64": "CFAR",
  "65": "CPCT",
  "66": "CURS",
  "67": "DIST",
  "68": "EXPT",
  "69": "FALT",
  "70": "FINA",
  "71": "FIN2",
  "72": "FIN3",
  "73": "HALF",
  "74": "HALN",
  "75": "HKNA",
  "76": "HNGL",
  "77": "HOJO",
  "78": "INIT",
  "79": "ISOL",
  "80": "JP78",
  "81": "JP83",
  "82": "JP90",
  "83": "JP04",
  "84": "LJMO",
  "85": "LOCL",
  "86": "MARK",
  "87": "MEDI",
  "88": "MED2",
  "89": "MKMK",
  "90": "NLCK",
  "91": "NUKT",
  "92": "PREF",
  "93": "PRES",
  "94": "VPAL",
  "95": "PSTF",
  "96": "PSTS",
  "97": "RKRF",
  "98": "RPHF",
  "99": "RUBY",
  "100": "SMPL",
  "101": "TJMO",
  "102": "TNAM",
  "103": "TRAD",
  "104": "VATU",
  "105": "VJMO",
  "106": "VKNA",
  "107": "VKRN",
  "108": "VRTR",
  "109": "VRT2",
  "110": "SS01",
  "111": "SS02",
  "112": "SS03",
  "113": "SS04",
  "114": "SS05",
  "115": "SS06",
  "116": "SS07",
  "117": "SS08",
  "118": "SS09",
  "119": "SS10",
  "120": "SS11",
  "121": "SS12",
  "122": "SS13",
  "123": "SS14",
  "124": "SS15",
  "125": "SS16",
  "126": "SS17",
  "127": "SS18",
  "128": "SS19",
  "129": "SS20",
  "130": "CV01",
  "131": "CV02",
  "132": "CV03",
  "133": "CV04",
  "134": "CV05",
  "135": "CV06",
  "136": "CV07",
  "137": "CV08",
  "138": "CV09",
  "139": "CV10",
  "140": "CV11",
  "141": "CV12",
  "142": "CV13",
  "143": "CV14",
  "144": "CV15",
  "145": "CV16",
  "146": "CV17",
  "147": "CV18",
  "148": "CV19",
  "149": "CV20",
  "150": "CV21",
  "151": "CV22",
  "152": "CV23",
  "153": "CV24",
  "154": "CV25",
  "155": "CV26",
  "156": "CV27",
  "157": "CV28",
  "158": "CV29",
  "159": "CV30",
  "160": "CV31",
  "161": "CV32",
  "162": "CV33",
  "163": "CV34",
  "164": "CV35",
  "165": "CV36",
  "166": "CV37",
  "167": "CV38",
  "168": "CV39",
  "169": "CV40",
  "170": "CV41",
  "171": "CV42",
  "172": "CV43",
  "173": "CV44",
  "174": "CV45",
  "175": "CV46",
  "176": "CV47",
  "177": "CV48",
  "178": "CV49",
  "179": "CV50",
  "180": "CV51",
  "181": "CV52",
  "182": "CV53",
  "183": "CV54",
  "184": "CV55",
  "185": "CV56",
  "186": "CV57",
  "187": "CV58",
  "188": "CV59",
  "189": "CV60",
  "190": "CV61",
  "191": "CV62",
  "192": "CV63",
  "193": "CV64",
  "194": "CV65",
  "195": "CV66",
  "196": "CV67",
  "197": "CV68",
  "198": "CV69",
  "199": "CV70",
  "200": "CV71",
  "201": "CV72",
  "202": "CV73",
  "203": "CV74",
  "204": "CV75",
  "205": "CV76",
  "206": "CV77",
  "207": "CV78",
  "208": "CV79",
  "209": "CV80",
  "210": "CV81",
  "211": "CV82",
  "212": "CV83",
  "213": "CV84",
  "214": "CV85",
  "215": "CV86",
  "216": "CV87",
  "217": "CV88",
  "218": "CV89",
  "219": "CV90",
  "220": "CV91",
  "221": "CV92",
  "222": "CV93",
  "223": "CV94",
  "224": "CV95",
  "225": "CV96",
  "226": "CV97",
  "227": "CV98",
  "228": "CV99",
  "PCAP": 0,
  "C2PC": 1,
  "CASE": 2,
  "CPSP": 3,
  "TITL": 4,
  "UNIC": 5,
  "ZERO": 6,
  "SINF": 7,
  "ORDN": 8,
  "AFRC": 9,
  "DNOM": 10,
  "NUMR": 11,
  "LIGA": 12,
  "CLIG": 13,
  "DLIG": 14,
  "HLIG": 15,
  "RLIG": 16,
  "AALT": 17,
  "CALT": 18,
  "RCLT": 19,
  "SALT": 20,
  "RVRN": 21,
  "VERT": 22,
  "SWSH": 23,
  "CSWH": 24,
  "NALT": 25,
  "CCMP": 26,
  "STCH": 27,
  "HIST": 28,
  "SIZE": 29,
  "ORNM": 30,
  "ITAL": 31,
  "RAND": 32,
  "DTLS": 33,
  "FLAC": 34,
  "MGRK": 35,
  "SSTY": 36,
  "KERN": 37,
  "FWID": 38,
  "HWID": 39,
  "HALT": 40,
  "TWID": 41,
  "QWID": 42,
  "PWID": 43,
  "JUST": 44,
  "LFBD": 45,
  "OPBD": 46,
  "RTBD": 47,
  "PALT": 48,
  "PKNA": 49,
  "LTRA": 50,
  "LTRM": 51,
  "RTLA": 52,
  "RTLM": 53,
  "ABRV": 54,
  "ABVM": 55,
  "ABVS": 56,
  "VALT": 57,
  "VHAL": 58,
  "BLWF": 59,
  "BLWM": 60,
  "BLWS": 61,
  "AKHN": 62,
  "CJCT": 63,
  "CFAR": 64,
  "CPCT": 65,
  "CURS": 66,
  "DIST": 67,
  "EXPT": 68,
  "FALT": 69,
  "FINA": 70,
  "FIN2": 71,
  "FIN3": 72,
  "HALF": 73,
  "HALN": 74,
  "HKNA": 75,
  "HNGL": 76,
  "HOJO": 77,
  "INIT": 78,
  "ISOL": 79,
  "JP78": 80,
  "JP83": 81,
  "JP90": 82,
  "JP04": 83,
  "LJMO": 84,
  "LOCL": 85,
  "MARK": 86,
  "MEDI": 87,
  "MED2": 88,
  "MKMK": 89,
  "NLCK": 90,
  "NUKT": 91,
  "PREF": 92,
  "PRES": 93,
  "VPAL": 94,
  "PSTF": 95,
  "PSTS": 96,
  "RKRF": 97,
  "RPHF": 98,
  "RUBY": 99,
  "SMPL": 100,
  "TJMO": 101,
  "TNAM": 102,
  "TRAD": 103,
  "VATU": 104,
  "VJMO": 105,
  "VKNA": 106,
  "VKRN": 107,
  "VRTR": 108,
  "VRT2": 109,
  "SS01": 110,
  "SS02": 111,
  "SS03": 112,
  "SS04": 113,
  "SS05": 114,
  "SS06": 115,
  "SS07": 116,
  "SS08": 117,
  "SS09": 118,
  "SS10": 119,
  "SS11": 120,
  "SS12": 121,
  "SS13": 122,
  "SS14": 123,
  "SS15": 124,
  "SS16": 125,
  "SS17": 126,
  "SS18": 127,
  "SS19": 128,
  "SS20": 129,
  "CV01": 130,
  "CV02": 131,
  "CV03": 132,
  "CV04": 133,
  "CV05": 134,
  "CV06": 135,
  "CV07": 136,
  "CV08": 137,
  "CV09": 138,
  "CV10": 139,
  "CV11": 140,
  "CV12": 141,
  "CV13": 142,
  "CV14": 143,
  "CV15": 144,
  "CV16": 145,
  "CV17": 146,
  "CV18": 147,
  "CV19": 148,
  "CV20": 149,
  "CV21": 150,
  "CV22": 151,
  "CV23": 152,
  "CV24": 153,
  "CV25": 154,
  "CV26": 155,
  "CV27": 156,
  "CV28": 157,
  "CV29": 158,
  "CV30": 159,
  "CV31": 160,
  "CV32": 161,
  "CV33": 162,
  "CV34": 163,
  "CV35": 164,
  "CV36": 165,
  "CV37": 166,
  "CV38": 167,
  "CV39": 168,
  "CV40": 169,
  "CV41": 170,
  "CV42": 171,
  "CV43": 172,
  "CV44": 173,
  "CV45": 174,
  "CV46": 175,
  "CV47": 176,
  "CV48": 177,
  "CV49": 178,
  "CV50": 179,
  "CV51": 180,
  "CV52": 181,
  "CV53": 182,
  "CV54": 183,
  "CV55": 184,
  "CV56": 185,
  "CV57": 186,
  "CV58": 187,
  "CV59": 188,
  "CV60": 189,
  "CV61": 190,
  "CV62": 191,
  "CV63": 192,
  "CV64": 193,
  "CV65": 194,
  "CV66": 195,
  "CV67": 196,
  "CV68": 197,
  "CV69": 198,
  "CV70": 199,
  "CV71": 200,
  "CV72": 201,
  "CV73": 202,
  "CV74": 203,
  "CV75": 204,
  "CV76": 205,
  "CV77": 206,
  "CV78": 207,
  "CV79": 208,
  "CV80": 209,
  "CV81": 210,
  "CV82": 211,
  "CV83": 212,
  "CV84": 213,
  "CV85": 214,
  "CV86": 215,
  "CV87": 216,
  "CV88": 217,
  "CV89": 218,
  "CV90": 219,
  "CV91": 220,
  "CV92": 221,
  "CV93": 222,
  "CV94": 223,
  "CV95": 224,
  "CV96": 225,
  "CV97": 226,
  "CV98": 227,
  "CV99": 228
};
exports["InstanceSwapPreferredValueType"] = {
  "0": "COMPONENT",
  "1": "STATE_GROUP",
  "COMPONENT": 0,
  "STATE_GROUP": 1
};
exports["ComponentPropType"] = {
  "0": "BOOL",
  "1": "TEXT",
  "2": "COLOR",
  "3": "INSTANCE_SWAP",
  "BOOL": 0,
  "TEXT": 1,
  "COLOR": 2,
  "INSTANCE_SWAP": 3
};
exports["ComponentPropNodeField"] = {
  "0": "VISIBLE",
  "1": "TEXT_DATA",
  "2": "OVERRIDDEN_SYMBOL_ID",
  "3": "INHERIT_FILL_STYLE_ID",
  "VISIBLE": 0,
  "TEXT_DATA": 1,
  "OVERRIDDEN_SYMBOL_ID": 2,
  "INHERIT_FILL_STYLE_ID": 3
};
exports["FileSource"] = {
  "0": "PixDoc",
  "1": "Figma",
  "2": "Sketch",
  "3": "Axure",
  "4": "XD",
  "5": "MG",
  "PixDoc": 0,
  "Figma": 1,
  "Sketch": 2,
  "Axure": 3,
  "XD": 4,
  "MG": 5
};
exports["FontIncorrect"] = {
  "0": "None",
  "1": "ImportDoc",
  "None": 0,
  "ImportDoc": 1
};
exports["WorkState"] = {
  "0": "ORIGIN",
  "1": "DESIGN",
  "2": "DEV",
  "ORIGIN": 0,
  "DESIGN": 1,
  "DEV": 2
};
exports["WrapMode"] = {
  "0": "NO_WRAP",
  "1": "WRAP",
  "NO_WRAP": 0,
  "WRAP": 1
};
exports["StackAlign"] = {
  "0": "AUTO",
  "1": "SPACE_BETWEEN",
  "AUTO": 0,
  "SPACE_BETWEEN": 1
};
exports["Directionality"] = {
  "0": "AUTO",
  "1": "LTR",
  "2": "RTL",
  "AUTO": 0,
  "LTR": 1,
  "RTL": 2
};
exports["VariableDataType"] = {
  "0": "BOOLEAN",
  "1": "FLOAT",
  "2": "STRING",
  "3": "ALIAS",
  "4": "COLOR",
  "5": "EXPRESSION",
  "6": "MAP",
  "7": "SYMBOL_ID",
  "8": "FONT_STYLE",
  "9": "TEXT_DATA",
  "10": "INVALID",
  "11": "NODE_FIELD_ALIAS",
  "BOOLEAN": 0,
  "FLOAT": 1,
  "STRING": 2,
  "ALIAS": 3,
  "COLOR": 4,
  "EXPRESSION": 5,
  "MAP": 6,
  "SYMBOL_ID": 7,
  "FONT_STYLE": 8,
  "TEXT_DATA": 9,
  "INVALID": 10,
  "NODE_FIELD_ALIAS": 11
};
exports["VariableResolvedDataType"] = {
  "0": "BOOLEAN",
  "1": "FLOAT",
  "2": "STRING",
  "4": "COLOR",
  "5": "MAP",
  "6": "SYMBOL_ID",
  "7": "FONT_STYLE",
  "8": "TEXT_DATA",
  "BOOLEAN": 0,
  "FLOAT": 1,
  "STRING": 2,
  "COLOR": 4,
  "MAP": 5,
  "SYMBOL_ID": 6,
  "FONT_STYLE": 7,
  "TEXT_DATA": 8
};
exports["VariableField"] = {
  "0": "MISSING",
  "1": "CORNER_RADIUS",
  "2": "PARAGRAPH_SPACING",
  "3": "PARAGRAPH_INDENT",
  "4": "STROKE_WEIGHT",
  "5": "STACK_SPACING",
  "6": "STACK_PADDING_LEFT",
  "7": "STACK_PADDING_TOP",
  "8": "STACK_PADDING_RIGHT",
  "9": "STACK_PADDING_BOTTOM",
  "10": "VISIBLE",
  "11": "TEXT_DATA",
  "12": "WIDTH",
  "13": "HEIGHT",
  "14": "RECTANGLE_TOP_LEFT_CORNER_RADIUS",
  "15": "RECTANGLE_TOP_RIGHT_CORNER_RADIUS",
  "16": "RECTANGLE_BOTTOM_LEFT_CORNER_RADIUS",
  "17": "RECTANGLE_BOTTOM_RIGHT_CORNER_RADIUS",
  "18": "BORDER_TOP_WEIGHT",
  "19": "BORDER_BOTTOM_WEIGHT",
  "20": "BORDER_LEFT_WEIGHT",
  "21": "BORDER_RIGHT_WEIGHT",
  "22": "VARIANT_PROPERTIES",
  "23": "STACK_COUNTER_SPACING",
  "24": "MIN_WIDTH",
  "25": "MAX_WIDTH",
  "26": "MIN_HEIGHT",
  "27": "MAX_HEIGHT",
  "28": "FONT_FAMILY",
  "29": "FONT_STYLE",
  "30": "FONT_VARIATIONS",
  "31": "OPACITY",
  "32": "FONT_SIZE",
  "34": "LETTER_SPACING",
  "36": "LINE_HEIGHT",
  "MISSING": 0,
  "CORNER_RADIUS": 1,
  "PARAGRAPH_SPACING": 2,
  "PARAGRAPH_INDENT": 3,
  "STROKE_WEIGHT": 4,
  "STACK_SPACING": 5,
  "STACK_PADDING_LEFT": 6,
  "STACK_PADDING_TOP": 7,
  "STACK_PADDING_RIGHT": 8,
  "STACK_PADDING_BOTTOM": 9,
  "VISIBLE": 10,
  "TEXT_DATA": 11,
  "WIDTH": 12,
  "HEIGHT": 13,
  "RECTANGLE_TOP_LEFT_CORNER_RADIUS": 14,
  "RECTANGLE_TOP_RIGHT_CORNER_RADIUS": 15,
  "RECTANGLE_BOTTOM_LEFT_CORNER_RADIUS": 16,
  "RECTANGLE_BOTTOM_RIGHT_CORNER_RADIUS": 17,
  "BORDER_TOP_WEIGHT": 18,
  "BORDER_BOTTOM_WEIGHT": 19,
  "BORDER_LEFT_WEIGHT": 20,
  "BORDER_RIGHT_WEIGHT": 21,
  "VARIANT_PROPERTIES": 22,
  "STACK_COUNTER_SPACING": 23,
  "MIN_WIDTH": 24,
  "MAX_WIDTH": 25,
  "MIN_HEIGHT": 26,
  "MAX_HEIGHT": 27,
  "FONT_FAMILY": 28,
  "FONT_STYLE": 29,
  "FONT_VARIATIONS": 30,
  "OPACITY": 31,
  "FONT_SIZE": 32,
  "LETTER_SPACING": 34,
  "LINE_HEIGHT": 36
};
exports["VariableScope"] = {
  "0": "ALL_SCOPES",
  "1": "TEXT_CONTENT",
  "2": "CORNER_RADIUS",
  "3": "WIDTH_HEIGHT",
  "4": "GAP",
  "5": "ALL_FILLS",
  "6": "FRAME_FILL",
  "7": "SHAPE_FILL",
  "8": "TEXT_FILL",
  "9": "STROKE",
  "10": "STROKE_FLOAT",
  "11": "EFFECT_FLOAT",
  "12": "EFFECT_COLOR",
  "13": "OPACITY",
  "14": "FONT_STYLE",
  "15": "FONT_FAMILY",
  "16": "FONT_SIZE",
  "17": "LINE_HEIGHT",
  "18": "LETTER_SPACING",
  "19": "PARAGRAPH_SPACING",
  "20": "PARAGRAPH_INDENT",
  "21": "FONT_VARIATIONS",
  "ALL_SCOPES": 0,
  "TEXT_CONTENT": 1,
  "CORNER_RADIUS": 2,
  "WIDTH_HEIGHT": 3,
  "GAP": 4,
  "ALL_FILLS": 5,
  "FRAME_FILL": 6,
  "SHAPE_FILL": 7,
  "TEXT_FILL": 8,
  "STROKE": 9,
  "STROKE_FLOAT": 10,
  "EFFECT_FLOAT": 11,
  "EFFECT_COLOR": 12,
  "OPACITY": 13,
  "FONT_STYLE": 14,
  "FONT_FAMILY": 15,
  "FONT_SIZE": 16,
  "LINE_HEIGHT": 17,
  "LETTER_SPACING": 18,
  "PARAGRAPH_SPACING": 19,
  "PARAGRAPH_INDENT": 20,
  "FONT_VARIATIONS": 21
};
exports["ExpressionFunction"] = {
  "0": "ADDITION",
  "1": "SUBTRACTION",
  "2": "RESOLVE_VARIANT",
  "3": "MULTIPLY",
  "4": "DIVIDE",
  "5": "EQUALS",
  "6": "NOT_EQUAL",
  "7": "LESS_THAN",
  "8": "LESS_THAN_OR_EQUAL",
  "9": "GREATER_THAN",
  "10": "GREATER_THAN_OR_EQUAL",
  "11": "AND",
  "12": "OR",
  "13": "NOT",
  "14": "STRINGIFY",
  "15": "TERNARY",
  "16": "VAR_MODE_LOOKUP",
  "17": "NEGATE",
  "18": "IS_TRUTHY",
  "ADDITION": 0,
  "SUBTRACTION": 1,
  "RESOLVE_VARIANT": 2,
  "MULTIPLY": 3,
  "DIVIDE": 4,
  "EQUALS": 5,
  "NOT_EQUAL": 6,
  "LESS_THAN": 7,
  "LESS_THAN_OR_EQUAL": 8,
  "GREATER_THAN": 9,
  "GREATER_THAN_OR_EQUAL": 10,
  "AND": 11,
  "OR": 12,
  "NOT": 13,
  "STRINGIFY": 14,
  "TERNARY": 15,
  "VAR_MODE_LOOKUP": 16,
  "NEGATE": 17,
  "IS_TRUTHY": 18
};
exports["NodeFieldAliasType"] = {
  "0": "MISSING",
  "1": "COMPONENT_PROP_ASSIGNMENTS",
  "MISSING": 0,
  "COMPONENT_PROP_ASSIGNMENTS": 1
};
exports["CodeSyntaxPlatform"] = {
  "0": "WEB",
  "1": "ANDROID",
  "2": "iOS",
  "WEB": 0,
  "ANDROID": 1,
  "iOS": 2
};
exports["TransformModifierType"] = {
  "0": "REPEAT",
  "1": "SYMMETRY",
  "2": "SKEW",
  "REPEAT": 0,
  "SYMMETRY": 1,
  "SKEW": 2
};
exports["RepeatType"] = {
  "0": "RADIAL",
  "1": "LINEAR",
  "RADIAL": 0,
  "LINEAR": 1
};
exports["UnitType"] = {
  "0": "PIXELS",
  "1": "RELATIVE",
  "PIXELS": 0,
  "RELATIVE": 1
};
exports["RepeatOrder"] = {
  "0": "FORWARD",
  "1": "REVERSE",
  "FORWARD": 0,
  "REVERSE": 1
};
exports["AnnotationPropertyType"] = {
  "0": "FILL",
  "1": "STROKE",
  "2": "WIDTH",
  "3": "HEIGHT",
  "4": "MIN_WIDTH",
  "5": "MIN_HEIGHT",
  "6": "MAX_WIDTH",
  "7": "MAX_HEIGHT",
  "8": "STROKE_WIDTH",
  "9": "CORNER_RADIUS",
  "10": "EFFECT",
  "11": "TEXT_STYLE",
  "12": "TEXT_ALIGN_HORIZONTAL",
  "13": "FONT_FAMILY",
  "14": "FONT_SIZE",
  "15": "FONT_WEIGHT",
  "16": "LINE_HEIGHT",
  "17": "LETTER_SPACING",
  "18": "STACK_SPACING",
  "19": "STACK_PADDING",
  "20": "STACK_MODE",
  "21": "STACK_ALIGNMENT",
  "22": "OPACITY",
  "23": "COMPONENT",
  "24": "FONT_STYLE",
  "25": "GRID_ROW_GAP",
  "26": "GRID_COLUMN_GAP",
  "27": "GRID_ROW_COUNT",
  "28": "GRID_COLUMN_COUNT",
  "29": "GRID_ROW_ANCHOR_INDEX",
  "30": "GRID_COLUMN_ANCHOR_INDEX",
  "31": "GRID_ROW_SPAN",
  "32": "GRID_COLUMN_SPAN",
  "FILL": 0,
  "STROKE": 1,
  "WIDTH": 2,
  "HEIGHT": 3,
  "MIN_WIDTH": 4,
  "MIN_HEIGHT": 5,
  "MAX_WIDTH": 6,
  "MAX_HEIGHT": 7,
  "STROKE_WIDTH": 8,
  "CORNER_RADIUS": 9,
  "EFFECT": 10,
  "TEXT_STYLE": 11,
  "TEXT_ALIGN_HORIZONTAL": 12,
  "FONT_FAMILY": 13,
  "FONT_SIZE": 14,
  "FONT_WEIGHT": 15,
  "LINE_HEIGHT": 16,
  "LETTER_SPACING": 17,
  "STACK_SPACING": 18,
  "STACK_PADDING": 19,
  "STACK_MODE": 20,
  "STACK_ALIGNMENT": 21,
  "OPACITY": 22,
  "COMPONENT": 23,
  "FONT_STYLE": 24,
  "GRID_ROW_GAP": 25,
  "GRID_COLUMN_GAP": 26,
  "GRID_ROW_COUNT": 27,
  "GRID_COLUMN_COUNT": 28,
  "GRID_ROW_ANCHOR_INDEX": 29,
  "GRID_COLUMN_ANCHOR_INDEX": 30,
  "GRID_ROW_SPAN": 31,
  "GRID_COLUMN_SPAN": 32
};
exports["AnnotationCategoryPreset"] = {
  "0": "NONE",
  "1": "ACCESSIBILITY",
  "2": "BEHAVIOR",
  "3": "CONTENT",
  "4": "DEVELOPMENT",
  "5": "INTERACTION",
  "NONE": 0,
  "ACCESSIBILITY": 1,
  "BEHAVIOR": 2,
  "CONTENT": 3,
  "DEVELOPMENT": 4,
  "INTERACTION": 5
};
exports["BlurOpType"] = {
  "0": "NORMAL",
  "1": "PROGRESSIVE",
  "NORMAL": 0,
  "PROGRESSIVE": 1
};

exports["decodeGUID"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["sessionID"] = bb.readVarUint();
  result["localID"] = bb.readVarUint();
  return result;
};

exports["encodeGUID"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["sessionID"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"sessionID\"");
  }

  var value = message["localID"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"localID\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeVector"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarFloat();
  result["y"] = bb.readVarFloat();
  return result;
};

exports["encodeVector"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"y\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeMatrix"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["m00"] = bb.readVarFloat();
  result["m01"] = bb.readVarFloat();
  result["m02"] = bb.readVarFloat();
  result["m10"] = bb.readVarFloat();
  result["m11"] = bb.readVarFloat();
  result["m12"] = bb.readVarFloat();
  return result;
};

exports["encodeMatrix"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["m00"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m00\"");
  }

  var value = message["m01"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m01\"");
  }

  var value = message["m02"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m02\"");
  }

  var value = message["m10"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m10\"");
  }

  var value = message["m11"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m11\"");
  }

  var value = message["m12"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m12\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeMatrix3f"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["m00"] = bb.readVarFloat();
  result["m01"] = bb.readVarFloat();
  result["m02"] = bb.readVarFloat();
  result["m10"] = bb.readVarFloat();
  result["m11"] = bb.readVarFloat();
  result["m12"] = bb.readVarFloat();
  result["m20"] = bb.readVarFloat();
  result["m21"] = bb.readVarFloat();
  result["m22"] = bb.readVarFloat();
  return result;
};

exports["encodeMatrix3f"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["m00"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m00\"");
  }

  var value = message["m01"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m01\"");
  }

  var value = message["m02"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m02\"");
  }

  var value = message["m10"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m10\"");
  }

  var value = message["m11"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m11\"");
  }

  var value = message["m12"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m12\"");
  }

  var value = message["m20"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m20\"");
  }

  var value = message["m21"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m21\"");
  }

  var value = message["m22"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"m22\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeColor"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["r"] = bb.readVarFloat();
  result["g"] = bb.readVarFloat();
  result["b"] = bb.readVarFloat();
  result["a"] = bb.readVarFloat();
  return result;
};

exports["encodeColor"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["r"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"r\"");
  }

  var value = message["g"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"g\"");
  }

  var value = message["b"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"b\"");
  }

  var value = message["a"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"a\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeRect"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarFloat();
  result["y"] = bb.readVarFloat();
  result["w"] = bb.readVarFloat();
  result["h"] = bb.readVarFloat();
  return result;
};

exports["encodeRect"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"y\"");
  }

  var value = message["w"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"w\"");
  }

  var value = message["h"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"h\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

exports["decodeCommandNum"] = function (bb) {
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["round"] = bb.readVarUint();
  result["count"] = bb.readVarUint();
  return result;
};

exports["encodeCommandNum"] = function (message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["round"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"round\"");
  }

  var value = message["count"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"count\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};
