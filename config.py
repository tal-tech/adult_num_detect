# !/usr/bin/python
# -*- coding: utf-8 -*-
import os
import time
import configparser
from enum import IntEnum

# from config.singleton import SingletonIns

from singleton import SingletonIns

class Env(IntEnum):
    local = 1
    test = 2
    pre = 3
    prod = 4


# 获取当前环境
def get_current_env():
    for i in range(3):
        if "CURRENT_ENV" in os.environ:
            break
        else:
            time.sleep(1)
            continue
    assert "CURRENT_ENV" in os.environ, "EnvError: CURRENT_ENV is not found."
    env = os.environ['CURRENT_ENV']
    assert env in ['LOCAL', 'TEST', 'PRE', 'PROD'], "KeyError: %s is not in [LOCAL', 'TEST', 'PRE', 'PROD']".format(env)

    if env == 'LOCAL':
        return Env.local
    elif env == 'TEST':
        return Env.test
    elif env == 'PRE':
        return Env.pre
    elif env == 'PROD':
        return Env.prod


# 全局标识当前环境
Current_Env = get_current_env()
# 项目根目录
ROOT_PATH = os.path.abspath(os.path.dirname(__file__)).split('config')[0]
# 配置文件目录
CONFIG_FILE_PATH = os.path.join(ROOT_PATH, 'config/config.ini')

# 各配置项名字：
# [local_server]
SECTION_LOCAL_SERVER = 'local_server'
SERVER_PORT = 'port'
SERVER_TYPE = 'server_type'
# [apollo_server]
SECTION_APOLLO_SERVER = 'apollo_server'
OPTION_APOLLO_HOST = 'host'
OPTION_APOLLO_APP = 'application'

# [mq_server]
CONFIG_SECTION_MQ_SERVER = 'mq_server'
CONFIG_OPTION_MQ_HOST = 'host'
CONFIG_OPTION_MQ_TOPIC = 'topic'
CONFIG_OPTION_MQ_TRANS = 'url_trans'

@SingletonIns
class Config:
    def __init__(self):
        self._server_port = int()
        self._apollo_host = str()
        self._apollo_app = str()
        self._server_type = str()

        # apollo配置项
        self._eureka_host = str()
        self._eureka_app_name = str()
        self._mq_host = str()
        self._mq_topic = str()
        self._server_url = str()
        self._api_type = str()
        self._url_trans = str()
        self._image_url_trans_timeout = int()
        self._image_download_timeout = int()
        self._read_config()

    def _read_config(self):
        # 本地环境读配置文件，paas三个环境读环境变量
        if Current_Env is Env.local:
            config = configparser.ConfigParser()
            print("config file: {}".format(CONFIG_FILE_PATH))
            assert os.path.exists(CONFIG_FILE_PATH), "config_file not exists:%s" % CONFIG_FILE_PATH
            config.read(CONFIG_FILE_PATH, encoding='utf-8-sig')

            # [local_server]
            assert config.has_section(SECTION_LOCAL_SERVER), "section [%s] not found" % SECTION_LOCAL_SERVER
            assert config.has_option(SECTION_LOCAL_SERVER, SERVER_PORT), "option [%s][%s] not found" % (SECTION_LOCAL_SERVER, SERVER_PORT)
            self._server_port = config.getint(SECTION_LOCAL_SERVER, SERVER_PORT)
            assert config.has_option(SECTION_LOCAL_SERVER, SERVER_TYPE), "option [%s][%s] not found" % (SECTION_LOCAL_SERVER, SERVER_TYPE)
            self._server_type = config.get(SECTION_LOCAL_SERVER, SERVER_TYPE)

            # [apollo_server]
            assert config.has_section(SECTION_APOLLO_SERVER), "section [%s] not found" % SECTION_APOLLO_SERVER
            assert config.has_option(SECTION_APOLLO_SERVER, OPTION_APOLLO_HOST), "option [%s][%s] not found" % (SECTION_APOLLO_SERVER, OPTION_APOLLO_HOST)
            self._apollo_host = config.get(SECTION_APOLLO_SERVER, OPTION_APOLLO_HOST)
            assert config.has_option(SECTION_APOLLO_SERVER, OPTION_APOLLO_APP), "option [%s][%s] not found" % (SECTION_APOLLO_SERVER, OPTION_APOLLO_APP)
            self._apollo_app = config.get(SECTION_APOLLO_SERVER, OPTION_APOLLO_APP)

            # [mq_server]
            assert config.has_section(CONFIG_SECTION_MQ_SERVER), "section [%s] not found" % CONFIG_SECTION_MQ_SERVER
            assert config.has_option(CONFIG_SECTION_MQ_SERVER, CONFIG_OPTION_MQ_TRANS), "option [%s][%s] not found" % (
            CONFIG_SECTION_MQ_SERVER, CONFIG_OPTION_MQ_TRANS)
            transurl = config.get(CONFIG_SECTION_MQ_SERVER,CONFIG_OPTION_MQ_TRANS)
            print(transurl)
            self._url_trans = config.get(CONFIG_SECTION_MQ_SERVER, CONFIG_OPTION_MQ_TRANS)

        else:  # yamal文件中env
            assert "APOLLO_HOST" in os.environ, "EnvError: APOLLO_HOST is not found."
            self._apollo_host = os.environ['APOLLO_HOST']
            assert "APOLLO_APPLICATION" in os.environ, "EnvError: APOLLO_APPLICATION is not found."
            self._apollo_app = os.environ['APOLLO_APPLICATION']
            assert "SERVICE_TYPE" in os.environ, "EnvError: SERVICE_TYPE is not found."
            self._server_type = os.environ['SERVICE_TYPE']
            # 在paas环境中都是以gunicorn运行的，此处无论设置什么值都会被gunicorn.conf中的端口号给取缔,
            # 但是因为eureka的存在，此处必须和gunicorn.conf中设置的端口号保持一致
            # 所以放入apollo中无意义，放入env中更是会让人误以为仅更改env中环境变量即可更改服务的端口号。
            self._server_port = 5012

    # 只读变量, 初始化即有
    @property
    def server_port(self):
        return self._server_port

    @property
    def apollo_host(self):
        return self._apollo_host

    @property
    def apollo_app(self):
        return self._apollo_app

    @property
    def server_type(self):
        return self._server_type

    # 读写变量, apollo获取
    @property
    def eureka_app_name(self):
        return self._eureka_app_name

    @eureka_app_name.setter
    def eureka_app_name(self, val):
        self._eureka_app_name = val

    @property
    def url_trans(self):
        return self._url_trans

    @url_trans.setter
    def url_trans(self, val):
        self._url_trans = val

    @property
    def image_url_trans_timeout(self):
        return self._image_url_trans_timeout

    @image_url_trans_timeout.setter
    def image_url_trans_timeout(self,val):
        self._image_url_trans_timeout = val

    @property
    def image_download_timeout(self):
        return self._image_download_timeout

    @image_download_timeout.setter
    def image_download_timeout(self, val):
        self._image_download_timeout = val

    @property
    def eureka_server(self):
        return self._eureka_host

    @eureka_server.setter
    def eureka_server(self, val):
        self._eureka_host = val

    @property
    def mq_host(self):
        return self._mq_host

    @mq_host.setter
    def mq_host(self, val):
        self._mq_host = val

    @property
    def mq_topic(self):
        return self._mq_topic

    @mq_topic.setter
    def mq_topic(self, val):
        self._mq_topic = val

    @property
    def server_url(self):
        return self._server_url

    @server_url.setter
    def server_url(self, val):
        self._server_url = val

    @property
    def api_type(self):
        return self._api_type

    @api_type.setter
    def api_type(self, val):
        self._api_type = val



