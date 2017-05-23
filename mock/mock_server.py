#!/usr/bin/env python

from flask import Flask
from flask import request
from flask import make_response
from urlparse import parse_qs
import json
import logging

log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

app = Flask("NATIVE MOCK SERVER")

FIREBASE_AUTH_FAIL_RESPONSE = "Server-key delivered or Sender is not authorized to perform request"

FIREBASE_DEVICE_TOKEN_FAIL_RESPONSE = "{\"multicast_id\":5160844598332076776,\"success\":0,\"failure\":1," \
                                      "\"canonical_ids\":0,\"results\":[{\"error\":\"InvalidRegistration\"}]}"

FIREBASE_SUCCESS_RESPONSE = "{\"multicast_id\":\"8855411935010968486\"," \
                            "\"success\":1,\"failure\":0,\"canonical_ids\":0," \
                            "\"results\":[{\"message_id\":\"0:1495528664983475%88d035ae88d035ae\"}]}"

FIREBASE_SERVICE_TOKEN = "foodtiny_token"

FIREBASE_DEVICE_TOKEN = "123456789"

SENGRID_SERVICE_TOKEN = FIREBASE_SERVICE_TOKEN

SENDGRID_AUTH_FAIL_RESPONSE = "{\"errors\":[{\"message\":" \
                              "\"The provided authorization grant is invalid, expired, or revoked\"," \
                              "\"field\":null,\"help\":null}]}"

TWILIO_SERVICE_TOKEN = "Zm9vZDp0aW55"   # result of base64 encode string "food:tiny"

TWILIO_AUTH_FAIL_RESPONSE = "{\"errors\":[{\"message\":" \
                            "\"The provided authorization grant is invalid, " \
                            "expired, or revoked\",\"field\":null,\"help\":null}]}"

TWILIO_SUCCESS_RESPONSE = "{\"sid\": \"SMd2143cc8ee5d4920b89c5f9e65db0825\", " \
                          "\"date_created\": \"Tue, 23 May 2017 08:37:54 +0000\", " \
                          "\"date_updated\": \"Tue, 23 May 2017 08:37:54 +0000\", " \
                          "\"date_sent\": null}"

ETCD_GET_RESPONSE = "{\"action\":\"get\"," \
                    "\"node\":{\"key\":\"/%s\"," \
                    "\"value\":\"404\",\"modifiedIndex\":379,\"createdIndex\":379}}"

ETCD_SET_RESPONSE = "{\"action\":\"set\",\"node\":{\"key\":\"/%s\",\"value\":\"%s\"," \
                    "\"modifiedIndex\":380,\"createdIndex\":380}," \
                    "\"prevNode\":{\"key\":\"%s\",\"value\":\"%s\",\"modifiedIndex\":379,\"createdIndex\":379}}"


@app.route("/")
def home():
    return "Hi guys! "


@app.route("/test", methods=['POST', 'GET'])
def on_test():
    if request.method == 'POST':
        return request.data
    return request.query_string


@app.route("/firebase", methods=['POST'])
def on_firebase():
    if request.headers.get("Authorization") != "key=%s" % FIREBASE_SERVICE_TOKEN:
        response = make_response(FIREBASE_AUTH_FAIL_RESPONSE)
        return response, 401

    data = json.loads(request.get_data())
    if data["to"] != FIREBASE_DEVICE_TOKEN:
        response = make_response(FIREBASE_DEVICE_TOKEN_FAIL_RESPONSE)
        return response, 200

    response = make_response(FIREBASE_SUCCESS_RESPONSE)
    return response, 200


@app.route("/twilio", methods=['POST'])
def on_twilio():
    if request.headers.get("Authorization") != "Basic %s" % TWILIO_SERVICE_TOKEN:
        return make_response(TWILIO_AUTH_FAIL_RESPONSE), 401
    return make_response(TWILIO_SUCCESS_RESPONSE), 201


@app.route("/sendgrid", methods=['POST'])
def on_sengrid():
    if request.headers.get("Authorization") != "Bearer %s" % SENGRID_SERVICE_TOKEN:
        return make_response(SENDGRID_AUTH_FAIL_RESPONSE), 401
    return make_response(), 202


@app.route('/etcd/v2/keys/<path:path>', methods=['PUT', 'GET'])
def etcd(path):
    if request.method == 'GET':
        return make_response(ETCD_GET_RESPONSE % path), 200
    data = parse_qs(request.get_data())
    key = path
    value = data.get('value')[0]
    return make_response(ETCD_SET_RESPONSE % (key, value, key, value))


@app.route("/search")
def on_search():
    return ""


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=9999)
